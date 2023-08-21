/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:49:02 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/21 18:07:54 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	exit_error_lexer(int err, t_mylist *list)
{	
	int i = 1;
	printf("Error: %d\n", err);
	//free(str);
	while (list->next != NULL)
	{	
		list = list->next;
		i++;
	}
	printf("nodes to free: %d", i);
	exit (1);
}