/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:47:57 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/11 22:55:37 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"
#include <stdio.h>

int	main(void)
{
	char	*message;
	t_lex	*lex_result;
	int		i;

	i = 0;
	while (1)
	{
		message = readline("MinniShell$: ");
		add_history(message);
		lex_result = lexer(message);
		while (i < lex_result->num)
		{
			if (lex_result[i].word != NULL)
				printf("%s\n", lex_result[i].word);
			else
				printf("%s\n", lex_result[i].redirection->sign);
			i++;
		}
		i = 0;
	}
	return (0);
}