/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:29:10 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:29:11 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
#typedef size_t;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	*ft_memcpy(void *destination, const void *const source, size_t number);
{
	register size_t	index;
	const char		*buffer1;
	char			*buffer2;

	if (!destination || !source)
		return (NULL);
	buffer1 = (char *)source;
	buffer2 = (char *)destination;
	index = 0;
	while (index < number)
	{
		buffer2[index] = buffer1[index];
		++index;
	}
	return (destination);
}
