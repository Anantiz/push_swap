/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list_add.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:35:02 by aurban            #+#    #+#             */
/*   Updated: 2023/11/23 17:03:36 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_nodeint	*ft_llint_data_add_back(t_llint *list, long data)
{
	t_nodeint	*node;

	node = malloc(sizeof(t_nodeint));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->previous = list->last;
	list->last = node;
	list->size++;
	return (node);
}

t_nodeint	*ft_llint_data_add_front(t_llint *list, long data)
{
	t_nodeint	*node;

	node = malloc(sizeof(t_nodeint));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = list->head;
	node->previous = NULL;
	list->head = node;
	list->size++;
	return (node);
}
