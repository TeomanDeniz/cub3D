/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:21:58 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:22:00 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "libft.h" /*
#    int ft_strlen(const char *const);
*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	ft_strlcat(char *dst, const char *src, int dstsize)
{
	register unsigned int	ecx;
	register unsigned int	eax;
	register unsigned int	sizedst;
	register unsigned int	sizesrc;

	sizedst = ft_strlen(dst);
	sizesrc = ft_strlen(src);
	eax = ft_strlen(dst);
	if (dstsize <= (signed int)sizedst)
		return (dstsize + sizesrc);
	ecx = 0;
	while (src[ecx] != '\0' && (signed int)eax < dstsize - 1)
	{
		dst[eax] = src[ecx];
		++eax;
		++ecx;
	}
	dst[eax] = '\0';
	return (sizedst + (signed int)sizesrc);
}
