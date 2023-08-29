/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:25:59 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/29 21:29:19 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"
// Need to fix: old notes strings copied to next ones
void	join_nodes(t_mylist *lst, t_explst **list)
{
	t_explst	*node;
	char		*new;
	char		*temp;

	node = *list;
	new = NULL;
	while (1)
	{
		temp = new;
		new = ft_strjoin(temp, node->str);
		// free(node->str);
		if (temp)
			free(temp);
		if (node->next == NULL)
			break ;
		node = node->next;
	}
	temp = lst->value;
	lst->value = new;
	free(temp);
}
void	expand(char *str, t_main *main, int *i, t_explst *node)
{
	*i = *i + 1;
	if (str[*i] == '?' && str[*i - 1] == '$')
		node->str = main->exit_code;
	*i = *i + 1;
	// while (lst->value[*i] != '\0' && (ft_isalnum(lst->value[*i]) || lst->value[*i] == '_'))
	// {
	// 		*i += 1;
	// }
	

}

void	check_expansions(t_main *main, t_mylist *lst,
	t_explst **node, t_explst **list)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (lst->value[i] != '\0')
	{
		new_node(node, list);
		while (lst->value[i] != '$' && lst->value[i] != '\0')
		{
			j++;
			i++;
		}
		if (j > 0)
		{
			(*node)->str = malloc(sizeof(char) * (j + 1));
			ft_strlcpy((*node)->str, &lst->value[i - j], j + 1);
			j = 0;
		}
		else if (lst->value[i] == '$')
			expand(lst->value, main, &i, *node);
	}
	if (list != NULL)
		join_nodes(lst, list);
}

void	expand_tokens(t_main *main)
{
	t_mylist	*head;
	t_explst	*temp_list;
	t_explst	*temp_node;

	head = main->list;
	temp_list = NULL;
	temp_node = NULL;
	while (1)
	{
		if (head->type == WRD || head->type == WRD_QUOTED)
		{

			check_expansions(main, head, &temp_node, &temp_list);
		}
		if (head->next == NULL)
			break ;
		head = head->next;
	}
}
