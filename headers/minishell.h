/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 03:58:45 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/12 19:29:19 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../lib/libft/libft.h"


// typedef struct s_redr
// {
// 	char	*sign;
// 	char	*value;
// }	t_redr;

typedef struct s_lex
{
	char	*sign;
	char	*value;
}	t_lex;

typedef struct s_input
{
	char	**cmd;
	t_redr	*redirections;
}	t_input;

//Functions

t_lex	*lexer(char *str);

#endif