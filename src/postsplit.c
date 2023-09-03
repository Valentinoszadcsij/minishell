/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:29:49 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/03 20:37:18 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	free_old_list(t_mylist *list)
{
	t_mylist	*head;
	t_mylist	*temp;

	head = list;
	while (1)
	{
		temp = head;
		head = head->next;
		free(temp->value);
		free(temp);
		if (head == NULL)
			break ;
	}
}

t_mylist	*new_split_node(int start, int end, char *str)
{
	t_mylist	*node;

	node = malloc(sizeof(t_mylist));
	node->type = WRD;
	node->value = ft_substr(str, start, end - start);
	node->next = NULL;
	return (node);
}

void	skip_chars(char *str, int *i)
{
	while (str[*i] != '\0' && str[*i] != ' ')
	{
		if (str[*i] == '\"')
		{
			*i += 1;
			while (str[*i] != '\"')
				*i += 1;
			*i += 1;
		}
		else if (str[*i] == '\'')
		{
			*i += 1;
			while (str[*i] != '\'')
				*i += 1;
			*i += 1;
		}
		else
			*i += 1;
	}
	printf("OUT\n");
}

t_mylist	*split_str(char *str)
{
	t_mylist	*list;
	t_mylist	*node;
	t_mylist	*head;
	int			j;
	int			i;

	list = NULL;
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
		{	
			i++;
			j++;
		}
		skip_chars(str, &i);
		node = new_split_node(j, i, str);
		j = i;
		if (!list)
			list = node;
		else
		{
			head = list;
			while (head->next != NULL)
				head = head->next;
			head->next = node;
		}
	}
	return (list);
}

void	postsplit(t_main *main)
{
	t_mylist	*head;
	t_mylist	*temp_list;
	t_mylist	*temp;

	head = main->list;
	temp_list = NULL;
	while (1)
	{	
		if (head->type == WRD || head->type == WRD_QUOTED)
		{
			if (!temp_list)
				temp_list = split_str(head->value);
			else
				temp->next = split_str(head->value);
			temp = temp_list;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = head->next;
		}
		if (!head->next)
			break ;
		head = head->next;
	}
	free_old_list(main->list);
	main->list = temp_list;
}
