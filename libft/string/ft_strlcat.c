/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:21:58 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:22:00 by hdeniz           ###   ########.fr       */
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

size_t
	ft_strlcat(char *const destination, const char *const source, \
register size_t destination_size)
{
	size_t			result;
	register size_t	source_index;
	register size_t	destination_index;
	register size_t	destination_string_len;
	register size_t	source_size;

	destination_string_len = ft_strlen(destination);
	source_size = ft_strlen(source);
	destination_index = destination_string_len;
	if (destination_size <= destination_string_len)
	{
		result = destination_size + source_size;
		return (result);
	}
	source_index = 0;
	while ((source[source_index] != '\0') && \
		(destination_index < (destination_size - 1)))
	{
		destination[destination_index] = source[source_index];
		++destination_index;
		++source_index;
	}
	destination[destination_index] = '\0';
	result = destination_string_len + source_size;
	return (result);
}
