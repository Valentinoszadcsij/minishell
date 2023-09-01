/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:28:29 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/31 20:02:44 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_explst	*new_node(t_explst **list)
{
	t_explst	*head;
	t_explst	*node;

	node = malloc(sizeof(t_explst));
	if (!node)
		exit(-1);//malloc error
	node->next = NULL;
	node->str = NULL;
	if (*list == NULL)
		*list = node;
	else
	{
		head = *list;
		while (1)
		{	
			if (head->next == NULL)
				break ;
			head = head->next;
		}
		head->next = node;
	}
	return (node);
}
