/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_indexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:42:12 by aurban            #+#    #+#             */
/*   Updated: 2023/11/27 13:06:13 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	find_data_in_array(long *array, long data, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == data)
			return (i);
		i++;
	}
	return (-1);
}

long	*ft_llint_to_arr(t_llint *llist)
{
	t_nodeint	*node;
	long		*list;
	size_t		i;

	list = malloc(sizeof(long) * llist->size);
	if (!list)
		return (NULL);
	i = 0;
	node = llist->head;
	while (node)
	{
		list[i++] = node->data;
		node = node->next;
	}
	return (list);
}

void	give_indexes(t_llint *list)
{
	long		*array;
	size_t		i;
	t_nodeint	*node;

	if (!list)
		return ;
	array = ft_llint_to_arr(list);
	ft_quicksort(array, 0, list->size - 1);
	i = 0;
	node = list->head;
	while (node)
	{
		node->index = find_data_in_array(array, node->data, list->size);
		node = node->next;
	}
}
