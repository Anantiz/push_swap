/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:54:01 by aurban            #+#    #+#             */
/*   Updated: 2023/11/24 15:30:28 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llint_print(t_llint *list)
{
	t_nodeint	*node;
	long		i;

	node = list->head;
	i = 0;
	while (node)
	{
		ft_printf("node %l: %l\n", i, node->data);
		node = node->next;
		i++;
	}
}

void	ft_llint_printm(t_llint *list)
{
	t_nodeint	*node;
	long		i;

	node = list->head;
	i = 0;
	ft_printf("Head: %x\tTail: %x\n", list->head, list->last);
	while (node)
	{
		ft_printf("node_%l: %l\tAddress: %x\n", i, node->data, node);
		node = node->next;
		i++;
	}
}
