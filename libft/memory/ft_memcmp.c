/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:29:19 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:29:21 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
#typedef size_t;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	ft_memcmp(const void *left, const void *right, size_t number)
{
	register size_t	index;
	unsigned char	*buffer1;
	unsigned char	*buffer2;

	buffer1 = (unsigned char *)left;
	buffer2 = (unsigned char *)right;
	index = 0;
	if (number == 0)
		return (0);
	--number;
	while ((buffer1[index] == buffer2[index]) && index < number)
		++index;
	return (buffer1[index] - buffer2[index]);
}
