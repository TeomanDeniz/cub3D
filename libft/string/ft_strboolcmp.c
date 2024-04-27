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
#include <stdbool.h> /*
#typedef bool;
# define false;
# define true;
*/
#include <stdlib.h> /*
#typedef size_t;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

bool
	ft_strboolcmp(const char *const string, const char *const compare)
{
	register size_t	index;

	if ((string == compare) || (!string && !compare))
		return (false);
	if (!string || !compare)
		return (true);
	index = 0;
	while ((string[index] == compare[index]) && \
		(!!string[index] && !!compare[index]))
		++index;
	if (!*compare && !*string)
		return (true);
	return (false);
}
