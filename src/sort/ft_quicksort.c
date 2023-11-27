/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:16:28 by aurban            #+#    #+#             */
/*   Updated: 2023/11/27 13:34:16 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	qs_swap_value(long *list, size_t a, size_t b)
{
	long	temp;

	temp = list[a];
	list[a] = list[b];
	list[b] = temp;
}

static long	qs_sub_sort(long *list, size_t low_index, size_t high_index)
{
	long	pivot;
	size_t	p1;
	size_t	p2;

	pivot = list[high_index];
	p1 = low_index;
	p2 = low_index;
	while (p2 <= high_index)
	{
		if (list[p2] < pivot)
		{
			qs_swap_value(list, p1, p2);
			p1++;
		}
		p2++;
	}
	qs_swap_value(list, p1, high_index);
	return (p1);
}

void	ft_quicksort(long *list, long low_index, long high_index)
{
	long	pivot_index;

	if (list && (low_index < high_index))
	{
		pivot_index = qs_sub_sort(list, low_index, high_index);
		ft_quicksort(list, low_index, pivot_index - 1);
		ft_quicksort(list, pivot_index + 1, high_index);
	}
}
