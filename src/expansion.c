/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:25:59 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/29 17:49:54 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	expand(char *str, t_main *main, int *i, t_explst *node)
{
	*i = *i + 1;
	if (str[*i] == '?' && str[*i - 1] == '$')
		node->str = main->exit_code;
	// while (lst->value[*i] != '\0' && (ft_isalnum(lst->value[*i]) || lst->value[*i] == '_'))
	// {
	// 		*i += 1;
	// }
	

}

void	check_expansions(t_main *main, t_mylist *lst)
{
	int			i;
	int			j;
	t_explst	*list;
	t_explst	*node;
	char		*temp;
	char		*new;

	i = 0;
	j = 0;
	node = NULL;
	list = NULL;
	while (lst->value[i] != '\0')
	{
		while (lst->value[i] != '$' && lst->value[i] != '\0')
		{
			j++;
			i++;
		}
		if (j > 0)
		{
			new_node(&node, &list);
			node->str = malloc(sizeof(char) * (j + 1));
			ft_strlcpy(node->str, &lst->value[i - j], j + 1);
			j = 0;
		}
		if (lst->value[i] == '$')
		{	
			new_node(&node, &list);
			expand(lst->value, main, &i, node);
			printf("%s, i = %d\n", node->str, i);
		}
		i++;
	}
	if (list != NULL)
	{
		node = list;
		new = NULL;
		while (node->next != NULL)
		{
			temp = new;
			new = ft_strjoin(temp, node->str);
			// free(node->str);
			if (temp)
				free(temp);
			node = node->next;
		}
		if (node->next == NULL)
		{
			temp = new;
			new = ft_strjoin(temp, node->str);
			// free(node->str);
			if (temp)
				free(temp);
		}
		temp = lst->value;
		lst->value = new;
		free(temp);
	}
}

void	expand_tokens(t_main *main)
{
	t_mylist	*head;

	head = main->list;
	while (head->next != NULL)
	{
		if (head->type == WRD || head->type == WRD_QUOTED)
			check_expansions(main, head);
		head = head->next;
	}
	if (head->next == NULL)
	{
		if (head->type == WRD || head->type == WRD_QUOTED)
			check_expansions(main, head);
	}
}