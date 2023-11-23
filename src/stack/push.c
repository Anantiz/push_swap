/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:28:05 by aurban            #+#    #+#             */
/*   Updated: 2023/11/23 12:36:07 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stck_push(t_stack *src, t_stack *dest)
{
	t_list	*second;

	if (src->name == 'A')
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
	second = src->head->next;
	ft_lstadd_front(&dest->head, src->head);
	src->head = second;
}
