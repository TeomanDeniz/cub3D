/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:20:54 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:20:55 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
#typedef size_t;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	ft_strncmp(const char *const left, const char *const right, \
register size_t size)
{
	register size_t	index;

	if (!left && !right)
		return (0);
	if (!left || !right)
	{
		if (!left)
			return (*left);
		return (*right);
	}
	index = 0;
	while ((index < size) && (left[index] != '\0' || right[index] != '\0'))
	{
		if (left[index] != right[index])
			return ((unsigned char)left[index] - (unsigned char)right[index]);
		++index;
	}
	return (0);
}
