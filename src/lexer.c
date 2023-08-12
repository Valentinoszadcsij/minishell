/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:45:49 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/12 19:57:05 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"
int	is_redir(char *str)
{
	if (str[0] == '|' && str[1] == '\0')
		return (0);
	else if (str[0] == '<' && str[1] != '<')
		return (0);
	else if (str[0] == '<' && str[1] == '<')
		return (1);
	else if (str[0] == '>' && str[1] == '>')
		return (1);
	else if (str[0] == '<' && str[1] == '<')
		return (1);
	
		
}
char	**tokenize(char **str)
{
	int		i;
	int		count;
	int		red_i;
	char	**tokens;

	i = 0;
	count = 0;
	while (str[i] != NULL)
	{
		red_i = is_redir(str[i]);
		if(red_i != -1)
		{
			if (str[i][red_i + 1] == '\0')
				count += 2;
			else
				count++;
		}
		else
			count++;
	}
}

t_lex	*lexer(char *str)
{
	char	**split_string;
	char	**tokens;

	split_string = ft_split(str, ' ');
	tokens = tokenize(split_string);
}
