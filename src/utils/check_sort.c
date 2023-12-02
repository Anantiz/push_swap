/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:27:10 by aurban            #+#    #+#             */
/*   Updated: 2023/11/29 17:02:16 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_llint *list)
{
	int			i;
	t_nodeint	*node;

	i = 0;
	if (!list)
		return (-2);
	node = list->head;
	while (node && node->next)
	{
		if (node->data > node->next->data)
			return (i);
		node = node->next;
		i++;
	}
	return (-1);
}
