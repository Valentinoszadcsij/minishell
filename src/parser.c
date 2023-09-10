/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:15:45 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/10 15:42:39 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	fix_types(t_main *main)
{
	t_mylist	*head;

	head = main->list;
	while (1)
	{
		if (head->type == LS || head->type == LSLS
			|| head->type == GRT || head->type == GRTGRT)
		{
			if (head->next && (head->next->type == WRD
					|| head->next->type == WRD_QUOTED))
				head->next->type = WRD_REDIR;
		}
		else if (head->type == WRD || head->type == WRD_QUOTED)
		{	
			head->type = WRD_CMD;
		}
		if (head->next == NULL)
			break ;
		head = head->next;
	}
}

void	init_data(t_main *main)
{
	int			count;

	count = count_procs(main->list);
	main->data = malloc(sizeof(t_data) * count);
	fix_types(main);
}

int	parser(t_main *main)
{
	t_mylist	*node;

	node = main->list;
	init_data(main);
	if (check_syntax(main) != 0)
	{		
		while (1)
		{
			if (node->value)
				free(node->value);
			if (node->next == NULL)
				break ;
			node = node->next;
		}
		return (printf("out\n") ,1);
	}
	return (0);
}