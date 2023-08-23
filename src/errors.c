/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:49:02 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/23 22:52:51 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	exit_error_lexer(t_mylist *list)
{	
	int			i;
	t_mylist	*head;
	t_mylist	*temp;

	i = 1;
	printf("bash: syntax error, no EOF found\n");
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
	exit (1);
}