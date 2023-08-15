/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:47:57 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/15 17:59:29 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"
#include <stdio.h>

int	main(void)
{
	char	*message;
	t_mylist	*list;
	t_mylist	*head;

	while (1)
	{
		message = readline("MinniShell$: ");
		add_history(message);
		list = lexer(message);
		head = list;
		while (1)
		{
			printf("Type: %d; Value: %s\n", head->type, head->value);
			if (head->next == NULL)
				break ;
			head = head->next;
		}
	}

	return (0);
}