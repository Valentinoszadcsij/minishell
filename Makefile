# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 20:54:02 by voszadcs          #+#    #+#              #
#    Updated: 2023/09/12 23:35:52 by voszadcs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

VPATH 	= src/
SRCS	= minishell.c parser.c lexer.c errors.c lexer_utils.c expansion.c\
		expansion_utils.c dup_env.c postsplit.c split_utils.c remove_quotes.c\
		parser_utils.c parse_redir.c do_redir.c
OBJS	= $(SRCS:.c=.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address

LIBFT	= lib/libft/libft.a

all: $(NAME)

$(LIBFT):
	make re -C lib/libft && make clean -C lib/libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME) -lreadline
	make clean

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all