/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 07:26:06 by hdeniz            #+#    #+#             */
/*   Updated: 2024/03/08 07:26:07 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../ft_math.h" /*
#typedef t_cast;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	ft_rand(register int min, register int max)
{
	static unsigned long	address;
	static int				seed;
	char					pointer[8192];
	t_cast					cast;

	seed = seed + 0;
	if (!seed)
	{
		cast.ptr = &pointer[seed];
		address = cast.integer + \
			((unsigned long long)__TIME__[0] \
			* (unsigned long long)__TIME__[1] \
			+ (unsigned long long)__TIME__[3] \
			* (unsigned long long)__TIME__[4] \
			+ (unsigned long long)__TIME__[6]) \
			* (unsigned long long)__TIME__[7];
	}
	address = (++seed, (address * 1103515245ULL + 12345ULL) & 0X7FFFFFFF);
	return (min + (int)((double)address / (0X7FFFFFFF / (max - min + 1))));
}
