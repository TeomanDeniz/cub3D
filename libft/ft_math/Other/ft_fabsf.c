/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fabsf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:31:50 by hdeniz            #+#    #+#             */
/*   Updated: 2023/03/19 21:13:52 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* INCLUDES */
#include "../ft_math.h"
/* INCLUDES */

float
	ft_fabsf(float x)
{
	if (ft_isnan(x))
		return (-(0.0F / 0.0F));
	if (x < 0.0F)
		return (x * -1.0F);
	return (x);
}
