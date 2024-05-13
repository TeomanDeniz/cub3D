/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrtf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:03:31 by hdeniz            #+#    #+#             */
/*   Updated: 2024/05/13 21:30:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../ft_math.h" /*
#    int ft_isnan(double);
#    int ft_isinf(double);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static __inline__ float	sqrt_checker(register float x);
/* *************************** [^] PROTOTYPES [^] *************************** */

float
	ft_sqrtf(register float x)
{
	float			guess;
	register float	last_guess;

	if (x <= 0.0F || ft_isnan(x) || ft_isinf(x))
		return (sqrt_checker(x));
	guess = x / 2.0F;
	last_guess = guess + 1.0F;
	while (guess != last_guess)
	{
		last_guess = guess;
		guess = (guess + x / guess) / 2.0F;
	}
	return (guess);
}

static __inline__ float
	sqrt_checker(float x)
{
	if (x < 0.0F)
		return (0.0F / 0.0F);
	return (x);
}
