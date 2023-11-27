/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:54:01 by aurban            #+#    #+#             */
/*   Updated: 2023/11/27 13:32:25 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llint_print(t_llint *list)
{
	t_nodeint	*node;
	long		i;

	if (!list)
		return ;
	node = list->head;
	i = 0;
	while (node)
	{
		ft_printf("node %l: %l\t\tindex= %u\n", i, node->data, \
			(unsigned int)node->index);
		node = node->next;
		i++;
	}
}

void	ft_llint_printm(t_llint *list)
{
	t_nodeint	*node;
	long		i;

	if (!list)
		return ;
	node = list->head;
	i = 0;
	ft_printf("Head: %x\tTail: %x\n", list->head, list->last);
	while (node)
	{
		ft_printf("node_%l: %l\tAddress: %x\t\tindex= %u\n", \
			i, node->data, node, (unsigned int)node->index);
		node = node->next;
		i++;
	}
}

void	*ft_llint_search_list(t_llint *list, long n)
{
	t_nodeint	*node;

	if (!list)
		return (NULL);
	node = list->head;
	while (node)
	{
		if (n == node->data)
			return (node);
	}
	return (NULL);
}
