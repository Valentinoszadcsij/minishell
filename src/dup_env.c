/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:28:48 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/01 19:08:16 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	**dup_env(char **env)
{
	char	**env_cpy;
	int		i;
	int		len;

	i = 0;
	while (env[i] != NULL)
		i++;
	env_cpy = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i] != NULL)
	{
		len = ft_strlen(env[i]);
		env_cpy[i] = ft_substr(env[i], 0, len);
		i++;
	}
	env_cpy[i] = NULL;
	return (env_cpy);
}