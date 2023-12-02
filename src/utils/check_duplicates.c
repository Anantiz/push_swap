/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:32:06 by aurban            #+#    #+#             */
/*   Updated: 2023/11/29 16:48:24 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*search_list_without_node(t_llint *list, t_nodeint *e_node, long n)
{
	t_nodeint	*node;

	node = list->head;
	while (node)
	{
		if (n == node->data && node != e_node)
			return (node);
		node = node->next;
	}
	return (NULL);
}

int	check_duplicates(t_llint *list)
{
	t_nodeint	*node;

	if (!list)
		return (0);
	node = list->head;
	while (node)
	{
		if (search_list_without_node(list, node, node->data) != NULL)
		{
			push_swap_print_error(1);
			return (1);
		}
		node = node->next;
	}
	return (0);
}
