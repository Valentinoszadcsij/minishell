/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:27:49 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/14 20:03:31 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*cpy_no_quotes(char *src, char *new)
{
	int	i;

	i = 0;
	while (*src != '\0')
	{
		if (*src != '\'' && *src != '\"')
		{
			new[i] = *src;
			i++;
			src++;
		}
		else
			src++;
	}
	return (new);
}

char	*rm_quotes(char *str)
{
	int		i;
	int		count;
	char	*temp;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\"' || str[i] == '\'')
			count++;
		i++;
	}
	if (count == 0)
		return (str);
	temp = malloc(sizeof(char) * (ft_strlen(str) - count + 1));
	temp[ft_strlen(str) - count] = '\0';
	return (cpy_no_quotes(str, temp));
}

char	*get_var(char *str, int i, char **env)
{
	char	*var;
	int		j;

	i++;
	j = i;
	while (str[i] != '\0' && str[i] != '$')
		i++;
	var = ft_substr(str, j, i - j);
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], var, ft_strlen(var)) == 0
			&& env[i][ft_strlen(var)] == '=')
			break ;
		else
			i++;
	}
	free(var);
	if (env[i] != NULL)
	{
		var = ft_strchr(env[i], '=');
		var++;
		return (ft_substr(var, 0, ft_strlen(var)));
	}
	return (NULL);
}

char	*expand_rl(char *str, t_main *main)
{
	char	*temp;
	char	*temp_1;
	int		i;

	i = 0;
	temp = NULL;
	if (str[i] == '$' && str[i + 1] == '?')
	{
		temp = ft_substr(ft_itoa(main->error_code),
				0, ft_strlen(ft_itoa(main->error_code)));
		i++;
	}
	else if (str[i] == '$' && str[i + 1] == '$')
		i++;
	else if (str[i] == '$')
	{
		temp_1 = temp;
		temp = ft_strjoin(temp, get_var(str, i, main->env));
		if (temp_1)
			free(temp_1);
	}
	if (!temp)
		return (str);
	return (free(str), temp);
}

int	heredoc(t_data *data, t_mylist *node, t_main *main)
{
	char	*message;
	char	*error;
	char	*delim;

	if (data->fd[0] != 0)
		close(data->fd[0]);
	data->fd[0] = open("temp.heredoc", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->fd[0] < 0)
		return (error = ft_strjoin("minishell: ", "temp.heredoc"),
			perror(error), free(error), 0);
	delim = rm_quotes(node->next->value);
	while (1)
	{
		message = readline("> ");
		if (ft_strncmp(message, delim, ft_strlen(message)) != 0)
		{	
			if (node->next->type == WRD_REDIR)
				message = expand_rl(message, main);
			ft_putstr_fd(message, data->fd[0]);
			ft_putchar_fd('\n', data->fd[0]);
		}
		else
			break ;
	}
	return (1);
}
