/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:17:18 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/10 15:43:48 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	syntax_error(t_main *main, int type)
{
	main->error_code = 258;
	if (type == LS)
		printf("minishell: syntax error near unexpected token `<'\n");
	else if (type == LSLS)
		printf("minishell: syntax error near unexpected token `<<'\n");
	else if (type == GRT)
		printf("minishell: syntax error near unexpected token `>'\n");
	else if (type == GRTGRT)
		printf("minishell: syntax error near unexpected token `>>'\n");

}

int	check_syntax(t_main *main)
{
	t_mylist *head;

	head = main->list;
	while (1)
	{
		if ((head->type == LS || head->type == LSLS || head->type == GRT
				|| head->type == GRTGRT)
			&& head->next->type != WRD_REDIR)
			return (syntax_error(main, head->next->type), 1);
		if (!head->next)
			break ;
		head = head->next;
	}
	return (0);
}