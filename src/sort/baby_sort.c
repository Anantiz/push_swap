/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baby_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:00:36 by aurban            #+#    #+#             */
/*   Updated: 2023/12/04 21:36:06 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	baby_sort(t_llint *stack)
{
	if (!stack || !stack->head)
		return (-1);
	if (stack->head->index > stack->last->index)
		rotate_a(stack);
	if (stack->head->index > stack->last->index)
		rotate_a(stack);
	else if (stack->head->next && stack->head->index > \
		stack->head->next->index)
		swap_a(stack);
	else if (stack->head->next && stack->head->next->index > \
		stack->last->index && stack->head->index < stack->head->next->index)
	{
		swap_a(stack);
		rotate_a(stack);
	}
	return (0);
}

static int	sort_five2(t_llint *a, t_llint *b, size_t og_size_b)
{
	baby_sort(a);
	while (b->size > og_size_b || check_sort(a) != -1)
	{
		if (b->head && a->head->index < b->head->index)
			rotate_a(a);
		else if (a->last->index == a->head->index - 1)
			rev_rotate_a(a);
		else if (b->head && b->head->index == a->head->index - 1)
		{
			if (!push_a(b, a))
				return (-1);
		}
		else
			rev_rotate_a(a);
	}
	return (0);
}

int	sort_five(t_llint *a, t_llint *b, t_lydt *lydt)
{
	size_t	og_size_b;

	og_size_b = b->size;
	if (a->last->index == (lydt->og_size - a->size))
		rev_rotate_a(a);
	while (a->last->index != lydt->og_size - 1)
	{
		if (a->head->index == (lydt->og_size - a->size))
		{
			if (!push_b(a, b))
				return (-1);
		}
		else
			rotate_a(a);
	}
	while (a->size > 3)
	{
		if (!push_b(a, b))
			return (-1);
		if (b->head->next && b->head->next->index > b->head->index)
			swap_b(b);
	}
	return (sort_five2(a, b, og_size_b));
}

int	magic_solver(t_data *d)
{
	d->lydt->top = 9;
	d->lydt->low = 0;
	if (sortzilla_layersort(d) == -1)
		return (-1);
	if (d->b->head && d->b->head->next && d->b->head->next->index \
		> d->b->head->index)
		swap_b(d->b);
	while (d->b->head)
		push_a(d->b, d->a);
	return (0);
}

/*
Currently, we want to send one layer at a time, in reverse order,
so first last layer, then second to last layer
*/
int	zilla_phaseb(t_llint *a, t_llint *b, t_lydt *lydt)
{
	int		layer;
	t_data	data;

	data.a = a;
	data.b = b;
	data.lydt = lydt;
	layer = lydt->layerzilla;
	if (lydt->og_size <= 8)
		return (magic_solver(&data));
	while (layer)
	{
		lydt->low = (layer - 1) * (lydt->og_size / lydt->layerzilla);
		lydt->top = (layer) * (lydt->og_size / lydt->layerzilla);
		if (layer == LAYERZILLA)
			lydt->top = lydt->og_size;
		if (sortzilla_layersort(&data) == -1)
			return (-1);
		layer--;
	}
	return (0);
}

//72 55 33 21 94
