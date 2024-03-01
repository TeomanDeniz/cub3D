/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:21:45 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:21:47 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int
	ft_strlcpy(char *dst, const char *src, int size)
{
	register int	ecx;

	ecx = -1;
	if (size > 0)
	{
		while (++ecx, src[ecx] && ecx < (size - 1))
			dst[ecx] = src[ecx];
		dst[ecx] = 0;
	}
	while (src[ecx])
		++ecx;
	return (ecx);
}
