/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lrintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 00:38:30 by hdeniz            #+#    #+#             */
/*   Updated: 2023/03/20 00:42:33 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* INCLUDES */
#include "../ft_math.h"
/* INCLUDES */

long int
	ft_lrintf(register float x)
{
	if (x > 0.0F)
		return ((long int)(x + 0.5F));
	if (x < 0.0F)
		return ((long int)(x - 0.5F));
	return (x);
}
