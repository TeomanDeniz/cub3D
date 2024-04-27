/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:29:36 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:29:38 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
#typedef size_t;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	*ft_memchr(const void *base, register int find, register size_t len)
{
	unsigned char	*buffer;

	if (!base)
		return (NULL);
	buffer = (unsigned char *)base;
	while (len)
	{
		if (*buffer == (unsigned char)find)
			return (buffer);
		++buffer;
		--len;
	}
	return (NULL);
}
