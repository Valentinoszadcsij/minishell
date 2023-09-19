/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:51:26 by ihama             #+#    #+#             */
/*   Updated: 2023/09/19 13:45:40 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	execute_builtins(t_data *data, t_main *main)
{

	if (!ft_strncmp(data->cmd[0], "echo", 4))
		execute_echo(data);
	else if (!ft_strncmp(data->cmd[0], "exit", 4))
		execute_exit(data);
	else if (!ft_strncmp(data->cmd[0], "pwd", 3))
		execute_pwd(data->cmd);
	else if (!ft_strncmp(data->cmd[0], "env", 3))
		execute_env(main);
	else if (!ft_strncmp(data->cmd[0], "export", 6))
		execute_export(data, main);
	else if (!ft_strncmp(data->cmd[0], "unset", 5))
		execute_unset(data, main);
	else if (!ft_strncmp(data->cmd[0], "cd", 2))
		execute_cd(data, main);
}

int	is_builtin(const char *command)
{
	if (command)
	{
		return (!ft_strncmp(command, "echo", 4)
		|| (!ft_strncmp(command, "exit", 4))
		|| (!ft_strncmp(command, "pwd", 3))
		|| (!ft_strncmp(command, "env", 3))
		|| (!ft_strncmp(command, "export", 6))
		|| (!ft_strncmp(command, "unset", 5))
		|| !ft_strncmp(command, "cd", 2));
	}
	else
		return (0);
}

char	*get_path_cmd(char *cmd, char **env)
{
	char	**all_path;
	char	*cmd_path;
	char	*new_sub;

	while (*env && !ft_strnstr(*env, "PATH=", 5))
		env++;
	new_sub = ft_substr(*env, 5, ft_strlen(*env) - 5);
	all_path = ft_split(new_sub, ':');
	free(new_sub);
	cmd = *ft_split(cmd, ' ');
	new_sub = ft_strjoin("/", cmd);
	while (*all_path)
	{
		cmd_path = ft_strjoin(*all_path, new_sub);
		if (cmd_path == 0)
			return (NULL);
		if (access(cmd_path, F_OK) == 0)
			break ;
		free(cmd_path);
		all_path++;
	}
	free(new_sub);
	free(cmd);
	return (cmd_path);
}

