/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:25:26 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/06 22:25:27 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
#typedef size_t;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

char
	ft_strcmp(const char *const string, const char *const compare)
{
	register size_t	index;

	if ((string == compare) || (!string && !compare))
		return (0);
	if (!string || !compare)
		return (1);
	index = 0;
	while ((string[index] == compare[index]) && \
		(!!string[index] && !!compare[index]))
		++index;
	return (string[index] - compare[index]);
}
