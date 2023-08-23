/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:45:49 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/23 16:08:40 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	word_token(char *str, t_mylist *list, int i)
{
	int	start;

	start = i;
	list->type = WRD;
	if (str[i] == '\0')
		return (list->type = -1, list->value = NULL, i);
	while (str[i] != '\0' && str[i] != ' ')
	{
		if (str[i] == '\"')
			check_double_quotes(str, &i, list);
		else if (str[i] == '\'')
			check_single_quotes(str, &i, list);
		i++;
	}
	return (list->value = ft_substr(str, start, i - start), i);
}

int	tokenize(char *str, t_mylist *list)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '<' && str[i + 1] != '<')
		return (list->type = LS, list->value = NULL, i + 1);
	else if (str[i] == '<' && str[i + 1] == '<')
		return (list->type = LSLS, list->value = NULL, i + 2);
	else if (str[i] == '>' && str[i + 1] != '>')
		return (list->type = GRT, list->value = NULL, i + 1);
	else if (str[i] == '>' && str[i + 1] == '>')
		return (list->type = GRTGRT, list->value = NULL, i + 2);
	else if (str[i] == '|')
		return (list->type = PIPE, list->value = NULL, i + 1);
	else
		return (word_token(str, list, i));
}

int	fill_list(t_mylist	**list, char *str, int *index)
{
	t_mylist	*node;
	t_mylist	*head;
	int			i;

	i = 0;
		node = malloc (sizeof(t_mylist));
	if (node == NULL)
		return (-1);//_error(ERR_MALLOC);
	node->next = NULL;
	i = tokenize(&str[*index], node);
	if (*list == NULL)
		*list = node;
	else
	{
		head = *list;
		while (head->next != NULL)
			head = head->next;
		if (node->type != -1)
			head->next = node;
		else
			free (node);
	}
	if (node->type == WRD_SINGLE_Q)
		return (WRD_SINGLE_Q);
	return (*index = *index + i, 0);
}

t_mylist	*lexer(char *str)
{
	t_mylist	*list;
	char		*current;
	int			index;
	int			err;

	list = NULL;
	current = str;
	index = 0;
	while (current[index] != '\0')
	{	
		err = fill_list(&list, current, &index);
		if (err != 0)
		{	
			free(str);
			exit_error_lexer(err, list);
		}
	}
	return (list);
}
