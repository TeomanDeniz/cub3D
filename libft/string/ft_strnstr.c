/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:20:35 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:20:36 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../libft.h" /*
# size_t ft_strlen(char *);
#*/
#include <stdlib.h> /*
#typedef size_t;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

char
	*ft_strnstr(const char *haystack, const char *const needle, \
register size_t len)
{
	register size_t	index_1;
	register size_t	index_2;
	register size_t	needle_len;

	index_1 = 0;
	if (!haystack || !needle)
		return (NULL);
	needle_len = ft_strlen(needle);
	if (needle_len == 0 || haystack == needle)
		return (haystack);
	while (haystack[index_1] != '\0' && index_1 < len)
	{
		index_2 = 0;
		while ((haystack[index_1 + index_2] != '\0') && \
			(needle[index_2] != '\0') && \
			(haystack[index_1 + index_2] == needle[index_2]) && \
			((index_1 + index_2) < len))
			++index_2;
		if (index_2 == needle_len)
			return (haystack + index_1);
		++index_1;
	}
	return (NULL);
}
