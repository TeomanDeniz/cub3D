/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:19:27 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:19:57 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../libft.h" /*
# size_t ft_strlen(char *);
# size_t ft_strlcpy(char *, char *, size_t);
#   char *ft_strdup(char *);
#*/
#include <stdlib.h> /*
#typedef size_t;
#   void *malloc(size_t);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

char
	*ft_substr(char const *string, register unsigned int start, \
register size_t len)
{
	char			*result;
	register size_t	index;

	if (!string)
		return (NULL);
	index = ft_strlen(string) - (size_t)start;
	if (len < index)
		index = len;
	if ((size_t)start > ft_strlen(string) - 1U)
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * (index + 1U));
	if (!result)
		return (NULL);
	ft_strlcpy(result, string + (size_t)start, index + 1U);
	return (result);
}
