/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:49:02 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/23 16:04:26 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	exit_error_lexer(int err, t_mylist *list)
{	
	int			i;
	t_mylist	*head;
	t_mylist	*temp;

	i = 1;
	printf("Error: %d\n", err);
	head = list;
	while (head != NULL)
	{	
		temp = head;
		if (temp->value != NULL)
			free(temp->value);
		free(temp);
		head = head->next;
		i++;
	}
	printf("nodes to free: %d", i);
	exit (1);
}