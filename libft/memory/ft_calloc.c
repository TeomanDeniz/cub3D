/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:35:49 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:35:53 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../libft.h" /*
#   void ft_bzero(void *, size_t);
#*/
#include <stdlib.h> /*
#typedef size_t;
#   void *malloc(size_t);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	*ft_calloc(register size_t count, register size_t size)
{
	register int	memory_size;
	void			*result;

	memory_size = count * size;
	result = malloc(memory_size);
	if (!result)
		return (NULL);
	ft_bzero(result, memory_size);
	return (result);
}
