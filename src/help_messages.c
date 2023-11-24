/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_messages.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:21:38 by aurban            #+#    #+#             */
/*   Updated: 2023/11/24 13:11:41 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	help_no_args(void)
{
	ft_printf("No arguments provided, please pass the numbers you wanna"
	" sort as separated arguments\n");
	return (1);
}

int	help_invalid_argument(char *str)
{
	ft_printf("Error: '%s' is an invalid argument\n", str);
	return (1);
}