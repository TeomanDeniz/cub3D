/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmodf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:48:05 by hdeniz            #+#    #+#             */
/*   Updated: 2024/05/09 22:08:23 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../ft_math.h" /*
#    int ft_isinf(double);
#  float ft_floorf(float);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* Note:
 * The original fmodf() function from <math.h> library not working right as
 * already a known bug in GNU.
 *
 * example: mod(-3, 5) = 2 (MUST BE)
 * But fmodf(-3.0, 5.0) returns -3.000000
 */

float
	ft_fmodf(float x, float y)
{
	if (ft_isinf(x))
		return (-0.0F / 0.0F);
	if (ft_isinf(y))
		return (x);
	return ((x) - (ft_floorf(x / y)) * (y));
}
