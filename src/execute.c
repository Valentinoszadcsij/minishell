/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:02:01 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/19 13:46:56 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_waitpid(t_main *main)
{
	int	i;
	int	status;

	i = 0;
	while (i < main->procs)
	{	
		waitpid(main->pid[i], &status, 0);
		i++;
	}
	//free
	if (WIFEXITED(status))
		main->error_code = WEXITSTATUS(status);
}

void	run_child_procs(t_main *main, int ind)
{
	char	*cmd;

	
	if (main->pid[ind] == 0)
	{
		if (main->data[ind].cmd[0])
			cmd = get_path_cmd(main->data[ind].cmd[0], main->env);
		if (main->procs > 1)
		{	
			do_pipes(main->pipes, ind, main->procs);
			close_all_pipes(main);
		}
		if (!do_redir(main, ind))
			exit (1);
		if (is_builtin(main->data[ind].cmd[0]))
			execute_builtins(&main->data[ind], main);
		else if (cmd)
		{		
			if (execve(cmd, main->data[ind].cmd, main->env) == -1)
			{
				// if (command has access)
				// 	perror
				// 	exit(126);
				// else
				// 	print comand not rl_eof_found
				// 	exit(127);
				perror("minishell:");
				main->error_code = errno;
			}
		}
		exit(EXIT_FAILURE);
	}
}

void	exec_procs(t_main *main)
{
	int	i;

	i = 0;
	if (main->procs > 1)
		init_pipes(main);
	main->pid = malloc(sizeof(pid_t) * main->procs);
	while (i < main->procs)
	{
		main->pid[i] = fork();
		if (main->pid[i] == -1)
		{
			main->error_code = 1;
			perror("fork");
			return ;
		}
		run_child_procs(main, i);
		i++;
	}
	if (main->pipes)
		close_all_pipes(main);
	ft_waitpid(main);
}

void	execute(t_main *main)
{
	int	temp_fd[2];

	if (main->procs == 1)
	{
		if (is_builtin(main->data[0].cmd[0]))
		{	
			temp_fd[0] = dup(STDIN_FILENO);
			temp_fd[1] = dup(STDOUT_FILENO);
			do_redir(main, 0);
			execute_builtins(&main->data[0], main);
			dup2(temp_fd[0], STDIN_FILENO);
			dup2(temp_fd[1], STDOUT_FILENO);
			close(temp_fd[0]);
			close(temp_fd[1]);
		}
		else
			exec_procs(main);
	}
	else
	{
		exec_procs(main);
	}
}