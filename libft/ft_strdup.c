/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:22:43 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/31 17:54:21 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "libft.h" /*
#    int ft_strlen(char *);
*/
#include <stdlib.h> /*
#   void *malloc(int);
*/
/* **************************** [^] INCLUDES [^] **************************** */

char
	*ft_strdup(const char *string)
{
	char				*result;
	unsigned long int	size;
	int					ecx;

	ecx = -1;
	size = ft_strlen(string);
	result = (char *) malloc(sizeof(char) * (size + 1UL));
	if (!result)
		return (0);
	while (++ecx, string[ecx] != '\0')
		result[ecx] = string[ecx];
	result[ecx] = 0;
	return (result);
}
