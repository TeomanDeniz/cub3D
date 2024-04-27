/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:20:09 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:20:10 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../libft.h" /*
# size_t ft_strlen(char *);
#*/
#include <stdlib.h> /*
#typedef size_t;
#*/
#include <stdbool.h> /*
# define bool
# define true
# define false
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ bool	ft_strtrim__checker(const char *const string, \
register char check);
/* *************************** [^] PROTOTYPES [^] *************************** */

char
	*ft_strtrim(char const *const left, char const *const right)
{
	char			*result;
	register size_t	index;
	register size_t	end;
	register size_t	start;

	if (!left || !right)
		return (NULL);
	end = ft_strlen(left);
	start = 0;
	while (left[start] != '\0' && ft_strtrim__checker(right, left[start]))
		++start;
	while (start < end && ft_strtrim__checker(right, left[end - 1]))
		--end;
	result = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!result)
		return (NULL);
	index = 0;
	while (start < end)
	{
		result[index] = left[start];
		++index;
		++start;
	}
	result[index] = '\0';
	return (result);
}

extern __inline__ bool
	ft_strtrim__checker(const char *const string, register char check)
{
	register size_t	index;

	index = 0;
	while (string[index] != '\0')
	{
		if (string[index] == check)
			return (true);
		++index;
	}
	return (false);
}
