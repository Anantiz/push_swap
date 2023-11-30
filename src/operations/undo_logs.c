/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo_logs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:14:18 by aurban            #+#    #+#             */
/*   Updated: 2023/11/30 17:20:47 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	undo_logs_2(t_data *d, t_nodeint *node)
{
	if (node->data == ROTATE_A)
		rev_rotate_a_log(d->a, NULL);
	else if (node->data == ROTATE_B)
		rev_rotate_b_log(d->b, NULL);
	else if (node->data == ROTATE_ROTATE)
		rev_rotate_rotate_log(d->a, d->b, NULL);
	else if (node->data == REV_ROTATE_A)
		rotate_a_log(d->a, NULL);
	else if (node->data == REV_ROTATE_B)
		rotate_b_log(d->b, NULL);
	else if (node->data == REV_ROTATE_ROTATE)
		rotate_rotate_log(d->a, d->b, NULL);
}

void	undo_logs(t_data *d, t_llint *logs)
{
	t_nodeint	*node;
	t_nodeint	*previous_node;

	if (!logs || !logs->last)
		return ;
	node = logs->last;
	// printf("\nLOGS\n");
	// ft_llint_print(logs);
	// printf("\n");
	while (node)
	{
		previous_node = node->previous;
		// printf("Undoing instruction: %ld\n",node->data);
		if (node->data == PUSH_A)
			push_b_log(d->a, d->b, NULL);
		else if (node->data == PUSH_B)
			push_a_log(d->b, d->a, NULL);
		else if (node->data == SWAP_A)
			swap_a_log(d->a, NULL);
		else if (node->data == SWAP_B)
			swap_b_log(d->b, NULL);
		else
			undo_logs_2(d, node);
		node = previous_node;
	}
}
