/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:29:01 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:29:02 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
#typedef size_t;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	ft_memmove__dont_handle_overlap(void *destination, \
const void *source, register size_t len);
extern __inline__ void	ft_memmove__handle_overlap(void *destination, \
const void *source, register size_t len);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	*ft_memmove(void *destination, void *source, register size_t len)
{
	const char	*buffer1;
	char		*buffer2;

	if ((destination == source) || !source)
		return (destination);
	if (!destination)
		return (source);
	buffer1 = (char *)source;
	buffer2 = (char *)destination;
	if (buffer2 > buffer1)
		ft_memmove__dont_handle_overlap(destination, source, len);
	else
		ft_memmove__handle_overlap(destination, source, len);
	return (buffer2);
}

extern __inline__ void
	ft_memmove__dont_handle_overlap(void *destination, const void *source, \
register size_t len)
{
	register size_t	index;

	index = len;
	while (index-- > 0)
	{
		((unsigned char *)destination)[index] = \
			((unsigned char *)source)[index];
	}
}

extern __inline__ void
	ft_memmove__handle_overlap(void *destination, const void *source, \
register size_t len)
{
	register size_t	index;

	index = 0;
	while (index < len)
	{
		((unsigned char *)destination)[index] = \
			((unsigned char *)source)[index];
		++index;
	}
}
