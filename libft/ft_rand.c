/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:38:23 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/14 13:14:42 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef union s_cast
{
	const char			*ptr;
	unsigned long long	integer;
}				t_cast;

int
	ft_rand(int min, int max)
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
