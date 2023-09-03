/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:29:49 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/03 03:49:44 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_mylist	*split_node(char *str, int *i)
{
	t_mylist	*node;
	int			j;

	j = 0;
	while (str[*i] != '\0' && str[*i] != ' ')
	{
		if (str[*i] == '\"')
		{
			*i += 1;
			j++;
			while (str[*i] != '\"')
			{
				*i += 1;
				j++;
			}
		}
		else if (str[*i] == '\'')
		{
			*i += 1;
			j++;
			while (str[*i] != '\"')
			{
				*i += 1;
				j++;
			}
		}
		j++;
		*i += 1;
	}
	node = malloc(sizeof(t_mylist) * 1);
	node->value = malloc(sizeof(char) * (*i - j + 1));
	node->value = ft_substr(str, *i - j, j);
	node->type = WRD;
	printf("value: %s\n", node->value);
	return (node);
}

void	postsplit(t_main *main)
{
	t_mylist	*list;
	t_mylist	*head;
	t_mylist	*temp;
	char		*old;
	int			i;

	list = main->list;
	head = list;
	i = 0;
	while (1)
	{
		if (head->type == WRD || head->type == WRD_QUOTED)
		{
			old = head->value;
			temp = head;
			while (old[i] != '\0')
			{
				while (old[i] == ' ')
					i++;
				head->next = split_node(old, &i);
				printf("i = %d\n", i);
				head = head->next;
			}
			printf("BREAK\n");	
			head->next = temp->next;
			//free(temp->value);
			//free(temp);
		}
		if (head->next == NULL)
		{
			break ;
		}
		head = head->next;
	}
}
