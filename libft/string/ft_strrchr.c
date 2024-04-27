/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:20:22 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:20:23 by hdeniz           ###   ########.fr       */
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
	*ft_strrchr(const char *const string, register int character)
{
	register size_t	index;

	if (!string)
		return (NULL);
	index = ft_strlen(string);
	while (index >= 0)
	{
		if (string[index] == (char)character)
			return (string + index);
		--index;
	}
	return (NULL);
}
