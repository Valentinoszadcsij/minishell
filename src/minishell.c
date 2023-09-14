/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:47:57 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/14 16:34:00 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	is_not_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (add_history(str), 0);
	return (1);
}
// Need to fix env duplication in case of no original env

int	main(int argc, char **argv, char **env)
{
	char		*message;
	t_main		main;
	int i = 0;

	if (argc > 1)
		return (printf("%s: %s: no such file or directory\n", argv[0], argv[1]), 1);
	main.env = dup_env(env);
	main.error_code = 0;
	while (1)
	{
		message = readline("minishell$: ");
		if (message[0] != '\0' && is_not_spaces(message))
		{
			add_history(message);
			main.list = NULL;
			lexer(message, &main);
			expand_tokens(&main);
			postsplit(&main);
			if (parser(&main) == 0)
			{
				while (i < main.procs)
				{
				 printf("fd in: %d\n", main.data[i].fd[0]);
				 printf("fd out: %d\n", main.data[i].fd[1]);
				 i++;
				}
			}
			i = 0;
		}
	}
	return (0);
}


			// 
			// {
			// 	while (i < main.procs)
			// 	{
			// 		printf("Command %d: ", i);
			// 		while (main.data[i].cmd[j] != NULL)
			// 		{
			// 			printf("%s ", main.data[i].cmd[j]);
			// 			free(main.data[i].cmd[j]);
			// 			j++;
			// 		}
			// 		printf("\ninput fd = %d\n", main.data[i].fd[0]);
			// 		printf("output fd = %d\n", main.data[i].fd[1]);
			// 		free(main.data[i].cmd);
			// 		i++;
			// 		j = 0;
			// 	}
			// // 	i = 0;
			// // 	while (i < main.procs)
			// // 	{
			// // 		if (close(main.data[i].fd[0]) < 0)
			// // 			printf("GALACTIC LOOP\n");
			// // 		if (close(main.data[i].fd[1]) < 0)
			// // 			printf("GALACTIC LOOP\n");
			// // 		i++;
			// // 	}
			// // 	free(main.data);
			// // }