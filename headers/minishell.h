/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 03:58:45 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/23 22:52:58 by voszadcs         ###   ########.fr       */
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

//Lexer types

# define PIPE 0
# define LSLS 1
# define GRTGRT 2
# define LS 3
# define GRT 4
# define WRD 5
# define WRD_QUOTED 6
# define WRD_SINGLE_Q -2

//Errors
#define ERR_MALLOC 10
// typedef struct s_redr
// {
// 	char	*sign;
// 	char	*value;
// }	t_redr;

typedef struct s_mylist
{
	int				type;
	char			*value;
	struct s_mylist	*next;
}	t_mylist;

typedef struct s_input
{
	char	**cmd;
}	t_input;

//Functions

t_mylist	*lexer(char *str);
void		exit_error_lexer(t_mylist *list);
void		check_double_quotes(char *str, int *i, t_mylist *list);
void		check_single_quotes(char *str, int *i, t_mylist *list);

#endif