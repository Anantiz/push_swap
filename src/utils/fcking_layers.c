/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcking_layers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:05:54 by aurban            #+#    #+#             */
/*   Updated: 2023/11/30 19:59:51 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
middle of the layer
*/
long	lydt_mid(t_lydt *lydt)
{
	if (lydt)
		return (lydt->low + ((lydt->top - lydt->low) / 2));
	return (-1);
}

/*
size from lowest to top
*/
long	lydt_layer_size(t_lydt *lydt)
{
	if (lydt)
		return ((lydt->top - lydt->low));
	return (-1);
}

/*
size from lowest + off to top
*/
long	lydt_layer_off7size(t_lydt *lydt)
{
	if (lydt)
		return ((lydt->top - (lydt->low + lydt->offset)));
	return (-1);
}

/*
lowest + offset
*/
long	lydt_lowest(t_lydt *lydt)
{
	if (lydt)
		return (lydt->low + lydt->offset);
	return (-1);
}
