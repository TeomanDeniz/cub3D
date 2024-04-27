/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:22:43 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:22:44 by hdeniz           ###   ########.fr       */
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
	*ft_strdup(const char *const string)
{
	char			*result;
	register size_t	index;

	if (!string)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(string) + 1));
	if (!result)
		return (NULL);
	index = 0;
	while (string[index] != '\0')
	{
		result[index] = string[index];
		++index;
	}
	result[index] = '\0';
	return (result);
}
