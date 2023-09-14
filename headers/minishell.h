/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 03:58:45 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/13 22:14:58 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"

//Lexer types

# define PIPE 0
# define LSLS 1
# define GRTGRT 2
# define LS 3
# define GRT 4
# define WRD 5
# define WRD_QUOTED 6
# define WRD_SINGLE_Q 7
# define WRD_REDIR 8
# define WRD_CMD 9
# define WRD_ARG 10
# define HEREDOC_QUOT 11

//Errors
# define ERR_MALLOC 10

typedef struct s_explst
{
	char			*str;
	struct s_explst	*next;
}	t_explst;
typedef struct s_mylist
{
	int				type;
	char			*value;
	struct s_mylist	*next;
}	t_mylist;

typedef struct s_data
{
	char	**cmd;
	int		fd[2];
	int		index;
}	t_data;

typedef struct s_main
{
	t_mylist	*list;
	char		**env;
	t_data		*data;
	int			procs;
	int			error_code;
}	t_main;

//Functions

void		lexer(char *str, t_main *main);
void		check_double_quotes(char *str, int *i, t_mylist *list);
void		check_single_quotes(char *str, int *i, t_mylist *list);
void		expand_tokens(t_main *main);
void		skip_char(char *str, int *j, int *i);
void		is_heredoc(t_mylist *node);
t_explst	*new_node(t_explst **list);
char		**dup_env(char **env);
void		postsplit(t_main *main);
void		skip_chars(char *str, int *i, int *j);
void		free_old_list(t_mylist *list);
void		list_iter(t_mylist **list, t_mylist *node);
void		remove_quotes(t_mylist *list);
int			parser(t_main *main);
void		parser_free(t_main *main);
int			count_procs(t_mylist *main);
int			parse_redir(t_main *main);
int			do_redir(t_data *data, t_mylist *node);
int			heredoc(t_data *data, t_mylist *node);
int			check_pipe(t_mylist *head, t_main *main, int *i);
void		parse_command(t_main *main);
#endif
