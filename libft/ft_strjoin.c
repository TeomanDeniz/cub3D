/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:22:13 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:22:15 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "libft.h" /*
#    int ft_strlen(const char *const);
#    int ft_strlcat(char *, const char *, int);
#    int ft_strlcpy(char *, const char *, int);
*/
#include <stdlib.h> /*
#   void *malloc(int);
*/
/* **************************** [^] INCLUDES [^] **************************** */

char
	*ft_strjoin(char const *s1, const char *s2)
{
	char					*str;
	register unsigned int	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (str);
}
