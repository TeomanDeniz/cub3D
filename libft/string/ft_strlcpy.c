/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:21:45 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:21:47 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
#typedef size_t;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

size_t
	ft_strlcpy(char *const destination, const char *const source, \
register size_t size)
{
	size_t	index;

	if (!destination || !source)
		return (0);
	index = 0;
	if (size > 0)
	{
		while (source[index] && index < (size - 1))
		{
			destination[index] = source[index];
			++index;
		}
		destination[index] = 0;
	}
	while (source[index])
		++index;
	return (index);
}
