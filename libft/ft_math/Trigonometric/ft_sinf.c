/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sinf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:38:23 by hdeniz            #+#    #+#             */
/*   Updated: 2023/03/20 03:34:48 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* INCLUDES */
#include "../ft_math.h"
/* INCLUDES */

#define S1 -1.66666666666666324348e-01F
#define S2 8.33333333332248946124e-03F
#define S3 -1.98412698298579493134e-04F
#define S4 2.75573137070700676789e-06F
#define S5 -2.50507602534068634195e-08F
#define S6 1.58969099521155010221e-10F

float
	ft_sinf(register float x)
{
	float			result;
	register float	x_x;

	x = ((x) - ((int)(x / M_PI_F)) * (M_PI_F));
	x_x = x * x;
	result = (x + x_x * x * \
		(S1 + x_x * S2 + x_x * \
		(S3 + x_x * \
		(S4 + x_x * \
		(S5 + x_x * S6)))));
	return (result);
}
