/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:45:49 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/11 22:54:58 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	init_red(t_lex *lex, char *str)
{
	int	i;

	i = 0;
	lex->redirection = malloc(sizeof(t_redr) * 1);
	while (str[i] != '\0')
	{
		if (str[i] == '|' && str[i + 1] == '\0')
		{
			lex->redirection->sign = malloc(sizeof(char) * 1);
			lex->redirection->sign[0] = '|';
			lex->redirection->value = NULL;
		}
		else if (str[i] == '<' && str[i + 1] == '\0')
		{
			lex->redirection->sign = malloc(sizeof(char) * 1);
			lex->redirection->sign[0] = '<';
			lex->redirection->value = NULL;
		}
		else
			printf("ERROR: input syntax error\n");
		i++;
	}
}

void	lex_init(t_lex *lex, char *str)
{
	if (str[0] == '|' || str[0] == '>'
		|| str[0] == '<')
	{	
		init_red(lex, str);
		lex->word = NULL;
	}
	else
	{
		lex->word = str;
	}
}

t_lex	*lexer(char *str)
{
	t_lex	*lex;
	char	**split_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	split_str = ft_split(str, ' ');
	while (split_str[i] != NULL)
		i++;
	lex = malloc(sizeof(t_lex) * (i + 1));
	lex->num = i;
	while (j < i)
	{	lex_init(&lex[j], split_str[j]);
		j++;}
	return (lex);
}
