/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:28:29 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/31 17:19:03 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	new_node(t_explst *node, t_explst *list)
{
	t_explst	*head;

	node = malloc(sizeof(t_explst));
	if (!node)
		exit(-1);//malloc error
	node->next = NULL;
	if (list == NULL)
	{	
		list = node;
	}
	else
	{
		printf("1\n");
		head = list;
		while (head->next != NULL)
			head = head->next;
		head->next = node;
	}
}