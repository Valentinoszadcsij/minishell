# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 20:54:02 by voszadcs          #+#    #+#              #
#    Updated: 2023/08/21 20:31:11 by voszadcs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

VPATH 	= src/
SRCS	= minishell.c parser.c lexer.c errors.c lexer_utils.c
OBJS	= $(SRCS:.c=.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

LIBFT	= lib/libft/libft.a

all: $(NAME)

$(LIBFT):
	make re -C lib/libft && make clean -C lib/libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME) -lreadline

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all