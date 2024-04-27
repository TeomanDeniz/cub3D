/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:21:08 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:21:09 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../libft.h" /*
# size_t ft_strlen(char *);
#*/
#include <stdlib.h> /*
#typedef size_t;
#   void *malloc(size_t);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

char
	*ft_strmapi(char const *const string, char (*function)(unsigned int, char))
{
	register size_t	index;
	char			*result;

	if (!string)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(string)) + 1);
	if (result == NULL)
		return (NULL);
	index = 0;
	while (string[index] != '\0')
	{
		result[index] = function(index, string[index]);
		++index;
	}
	result[index] = '\0';
	return (result);
}
