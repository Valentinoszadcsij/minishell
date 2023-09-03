/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:47:57 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/03 03:32:17 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"
#include <stdio.h>


//Continue copying enva and working on expansion
int	main(int argc, char **argv, char **env)
{
	char		*message;
	t_main		main;
	t_mylist	*head;

	if (argc > 1)
		return (printf("%s: %s: no such file or directory\n", argv[0], argv[1]), 1);
	main.env = dup_env(env);
	while (1)
	{
		message = readline("minishell$: ");
		if (message[0] != '\0')
		{
			add_history(message);
			main.list = NULL;
			main.exit_code = malloc(sizeof(char) + 1);
			main.exit_code[0] = '0';
			main.exit_code[1] = '\0';
			lexer(message, &main);
			expand_tokens(&main);
			postsplit(&main);
			head = main.list;
			while (1)
			{
				printf("Type: %d; Value: %s\n", head->type, head->value);
				if (head->next == NULL)
					break ;
				head = head->next;
			}
		}
	}
	return (0);
}