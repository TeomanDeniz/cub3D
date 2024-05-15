/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strboolcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:23:25 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/06 22:23:26 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
#typedef size_t;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	ft_strboolcmp(const char *const string, const char *const compare)
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
	if (!*compare && !*string)
		return (1);
	return (0);
}
