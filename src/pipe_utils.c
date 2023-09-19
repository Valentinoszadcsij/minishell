/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:27:21 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/18 18:19:54 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	init_pipes(t_main *main)
{
	int	i;

	i = 0;
	main->pipes = malloc(sizeof(t_pipes) * (main->procs - 1));
	while (i < (main->procs - 1))
	{
		pipe(main->pipes[i].pipe);
		//printf("pipe[%d,%d]\n", main->pipes[i].pipe[0], main->pipes[i].pipe[1]);
		i++;
	}
}

void	do_pipes(t_pipes *pipes, int ind, int procs)
{
	//fprintf(stderr, "pipe[%d,%d]\n", pipe[0], pipe[1]);
	if (ind == 0)
	{
		//close(pipes[ind].pipe[0]);
		// printf("_______%d________\n", ind);
		// printf("Before :in: %d, out: %d\n", pipes[ind].pipe[0], pipes[ind].pipe[1]);
		dup2(pipes[ind].pipe[1], STDOUT_FILENO);
		// close(pipes[ind].pipe[1]);
		// printf("After :in: %d\n", pipes[ind].pipe[0]);
	}
	else if (ind == (procs - 1))
	{
		//close(pipes[ind].pipe[1]);
		// printf("_______%d________\n", ind);
		dup2(pipes[ind - 1].pipe[0], STDIN_FILENO);
		// fprintf(stderr, "pipe: %d", pipes[ind - 1].pipe[0]);
		// close(pipes[ind - 1].pipe[0]);
	}
	else
	{
		//close(pipes[ind].pipe[0]);
		// printf("_______%d________\n", ind);
		// printf("in: %d, out: %d\n", pipes[ind - 1].pipe[0], pipes[ind - 1].pipe[1]);
		// printf("in: %d, out: %d\n", pipes[ind].pipe[0], pipes[ind].pipe[1]);
		dup2(pipes[ind - 1].pipe[0], STDIN_FILENO);
		// close(pipes[ind - 1].pipe[0]);
		dup2(pipes[ind].pipe[1], STDOUT_FILENO);
		// close(pipes[ind].pipe[1]);
		//close(pipes[ind - 1].pipe[1]);
	}
}
void	close_all_pipes(t_main *main)
{
	int	i;

	i = 0;
	while (i < (main->procs - 1))
	{
		close(main->pipes[i].pipe[0]);
		close(main->pipes[i].pipe[1]);
		i++;
	}
}
