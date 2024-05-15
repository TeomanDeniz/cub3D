/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                    	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:19:41 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/06 22:19:43 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../libft.h" /*
#   char *ft_memmove(void *, void *, size_t);
#   void *ft_calloc(size_t, size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

char	
	*ft_strcdup(char *string, register char charcater)
{
	char			*result;
	register int	string_size;

	string_size = 0;
	if (!string)
		return ((void *)0);
	while (string[string_size] && string[string_size] != charcater)
		++string_size;
	if (charcater != 0)
		++string_size;
	result = ft_calloc((string_size + 1), sizeof(char *));
	if (result == NULL)
		return (NULL);
	result = ft_memmove(result, string, string_size);
	return (result);
}
