/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortzilla_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:32:30 by aurban            #+#    #+#             */
/*   Updated: 2023/12/01 15:54:10 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_node(t_llint *a, t_llint *b, long index)
{
	long	position;

	if (!b->head)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	position = search_stack(b, index);
	if (position > (long)(b->size / 2))
	{
		while (b->head && (long)b->head->index != index)
			rev_rotate_b(b);
	}
	else
	{
		while (b->head && (long)b->head->index != index)
		{
			rotate_b(b);
		}
	}
	if (push_a(b, a) == NULL)
		return (-1);
	return (0);
}

long	search_stack(t_llint *stack, long index)
{
	t_nodeint	*node;
	long		i;

	i = 0;
	node = stack->head;
	while (node)
	{
		i++;
		if ((long)node->index == index)
			return (i);
		node = node->next;
	}	
	return (0);
}

long	how_expensive_are_you(t_llint *a, t_llint *b, long index)
{
	long	position;
	long	cost;

	if (index == 0 || index == (long)a->head->index)
		return (0);
	position = search_stack(b, index);
	if (position < (long)(b->size / 2))
		cost = position;
	else
		cost = -(b->size - position + 1);
	return (cost);
}
