/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:20:00 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/21 20:33:49 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	check_double_quotes(char *str, int *i, t_mylist *list)
{
	*i = *i + 1;
	while (str[*i] != '\"' && str[*i] != '\0')
		*i = *i + 1;
	if (str[*i] == '\0')
		list->type = WRD_SINGLE_Q;
}

void	check_single_quotes(char *str, int *i, t_mylist *list)
{
	*i = *i + 1;
	while (str[*i] != '\'' && str[*i] != '\0')
		*i = *i + 1;
	if (str[*i] == '\0')
		list->type = WRD_SINGLE_Q;
}