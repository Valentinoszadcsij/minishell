/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:34:21 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/16 19:49:32 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	count_procs(t_mylist *list)
{
	t_mylist	*head;
	int			i;

	i = 0;
	head = list;
	while (1)
	{
		if (head->type == PIPE)
			i++;
		if (!head->next)
			break ;
		head = head->next;
	}
	return (++i);
}

char	*here_file_name(int num)
{
	char	*name;
	char	*s;

	s = ft_itoa(num);
	name = ft_strjoin("heredoc_tmp_", s);
	free (s);
	return (name);
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