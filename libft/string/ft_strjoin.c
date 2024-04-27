/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:22:13 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:22:15 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../libft.h" /*
# size_t ft_strlen(char *);
# size_t ft_strlcpy(char *, char *, size_t);
# size_t ft_strlcat(char *, char *, size_t);
#*/
#include <stdlib.h> /*
#typedef size_t;
#   void *malloc(size_t);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

char
	*ft_strjoin(char const *const left, const char *const right)
{
	char			*result;
	register size_t	left_size;
	register size_t	right_size;

	if (!left || !right)
		return (NULL);
	left_size = ft_strlen(left);
	right_size = ft_strlen(right);
	result = (char *)malloc(sizeof(char) * (left_size + right_size + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, left, left_size + 1);
	ft_strlcat(result, right, left_size + right_size + 1);
	return (result);
}
