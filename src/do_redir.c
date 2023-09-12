/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:09:10 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/13 01:12:10 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	redir_input(t_data *data, t_mylist *node)
{
	char	*error;

	if (data->fd[0] != -1)
		close(data->fd[0]);
	else
		data->fd[0] = open(node->next->value, O_RDONLY);
	if (data->fd[0] == -1)
	{	
		error = ft_strjoin("minishell: ", node->next->value);
		return (perror(error), free(error), 0);
	}
	return (1);
}

int	do_redir(t_data *data, t_mylist *node)
{
	if (node->type == LS)
		if (!redir_input(data, node))
			return (0);
	// else if (node->type == GRT)
	// 	redir_output(data, node);
	// else if (node->type == GRTGRT)
	// 	redir_append(data, node);
	return (1);
}