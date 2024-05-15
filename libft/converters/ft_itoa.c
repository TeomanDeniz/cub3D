/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:34:11 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:34:15 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
#   void *malloc(size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ unsigned short	ft_itoa__numlen(register int number);
/* *************************** [^] PROTOTYPES [^] *************************** */

char
	*ft_itoa(register int number)
{
	char					*result;
	register unsigned short	num_digits;

	num_digits = ft_itoa__numlen(number);
	result = (char *)malloc(sizeof(char) * (num_digits + 1U));
	if (!result)
		return (NULL);
	if (number == 0)
		result[0] = 48;
	if (number < 0)
	{
		res[0] = '-';
		number = ((~number) + 1);
	}
	result[num_digits] = '\0';
	while (((num_digits - 1U) >= 0) && ((unsigned int)number > 0))
	{
		result[num_digits - 1U] = ((unsigned int)number % 10) + '0';
		number = (unsigned int)number / 10;
		--num_digits;
	}
	return (result);
}

extern __inline__ unsigned short
	ft_itoa__numlen(register int number)
{
	unsigned short	result;

	result = -1;
	if (number < 0)
	{
		number = ((~number) + 1);
		++result;
	}
	if (number == 0)
		return ((short)1U);
	while (++result, !!number)
		number = number / 10;
	return (result);
}
