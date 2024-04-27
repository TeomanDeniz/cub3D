/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:28:42 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:28:44 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
#typedef size_t;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	*ft_memset(void *base, register int character, register size_t len)
{
	register size_t	index;

	index = 0;
	while (index < len)
	{
		((char *)base)[index] = character;
		++index;
	}
	return (base);
}
