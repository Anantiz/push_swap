/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list_del.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:42:16 by aurban            #+#    #+#             */
/*   Updated: 2023/11/30 16:51:09 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_llint_del_node(t_llint *list, t_nodeint *node)
{
	if (!node || !list)
		return (NULL);
	// printf("ADDR: %p\n",node);
	// printf("N: %p\n",node->next);
	// printf("P: %p\n",node->previous);
	// printf("1\n");
	// fflush(NULL);
	if (node == list->head)
		list->head = node->next;
	if (node == list->last)
		list->last = node->previous;
	//printf("2\n");
	// fflush(NULL);
	if (node->next)
		node->next->previous = node->previous;
	//printf("2.5\n");
	// fflush(NULL);
	if (node->previous != NULL)
	{
	// 	printf("2.8\n");
	// 	fflush(NULL);
		node->previous->next = node->next;
		// printf("2.9\n");
		// fflush(NULL);
	}
	// printf("3\n");
	// fflush(NULL);
	free(node);
	list->size--;
	return (NULL);
}

void	*ft_llint_del_list(t_llint *list)
{
	t_nodeint	*node;
	t_nodeint	*next;

	if (!list)
		return (NULL);
	node = list->head;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(list);
	return (NULL);
}
