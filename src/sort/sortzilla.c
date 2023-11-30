/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortzilla.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:45:19 by aurban            #+#    #+#             */
/*   Updated: 2023/11/30 20:00:59 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	zilla_get_layers(t_lydt *lydt, size_t layer)
{
	layer *= 2;
	lydt->low = layer * (lydt->og_size / lydt->layerzilla);
	layer += 2;
	lydt->top = layer * (lydt->og_size / lydt->layerzilla);
	if (layer == lydt->layerzilla)
		lydt->top = lydt->og_size;
}

static void	rotate_opti_asf(t_data *d, size_t *loop_count, size_t sa)
{
	if ((d->a->head && d->a->head->index > d->lydt->top && *loop_count < sa) \
		|| (d->a->head->index == d->lydt->og_size - 1 || d->a->head->index \
		== d->lydt->og_size - 2 || d->a->head->index == d->lydt->og_size - 3 \
		|| d->a->head->index == d->lydt->og_size - 4 || d->a->head->index \
		== d->lydt->og_size - 5))
	{
		rotate_rotate(d->a, d->b);
		(*loop_count)++;
	}
	else
		rotate_b(d->b);
}

int	zilla_layering2(t_data *d, t_nodeint *nd, size_t *loop_count, size_t sa)
{
	if (nd->index == d->lydt->og_size - 1 || nd->index == d->lydt->og_size - 2 \
		|| nd->index == d->lydt->og_size - 3 || nd->index \
		== d->lydt->og_size - 4 || nd->index == d->lydt->og_size - 5)
		rotate_a(d->a);
	else if (nd->index >= d->lydt->low && nd->index < d->lydt->top)
	{
		nd = push_b(d->a, d->b);
		if (!nd)
			return (-1);
		if (nd->next && nd->next->index == nd->index + 1)
			swap_b(d->b);
		if (nd->index < (size_t)lydt_mid(d->lydt))
			rotate_opti_asf(d, loop_count, sa);
	}
	else
		rotate_a(d->a);
	return (0);
}

/*
PUSH TO B WITH LAYERING
*/
int	zilla_layering(t_llint *a, t_llint *b, t_lydt *lydt)
{
	t_nodeint	*node;
	size_t		layer;
	size_t		loop_count;
	size_t		start_a_size;
	t_data		d;

	d.a = a;
	d.b = b;
	d.lydt = lydt;
	layer = 0;
	while (layer < (lydt->layerzilla / 2))
	{
		loop_count = 0;
		node = a->head;
		start_a_size = a->size;
		zilla_get_layers(lydt, layer);
		while (a->size > 5 && loop_count++ < start_a_size)
		{
			zilla_layering2(&d, node, &loop_count, start_a_size);
			node = a->head;
		}
		layer++;
	}
	return (0);
}

int	sortzilla(t_llint *a, t_llint *b)
{
	t_lydt	lydt;

	if (!a || !b)
		return (1);
	if (check_sort(a) == -1)
		return (0);
	lydt.og_size = a->size;
	if (a->size <= 5)
		return (sort_five(a, b, &lydt));
	else if (a->size <= 110)
		lydt.layerzilla = LAYERZILLA_SMALL;
	else
		lydt.layerzilla = LAYERZILLA;
	if (zilla_layering(a, b, &lydt))
		return (-1);
	if (sort_five(a, b, &lydt) == -1)
		return (-1);
	if (zilla_phaseb(a, b, &lydt) == -1)
		return (-1);
	return (0);
}
