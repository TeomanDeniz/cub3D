/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:19:41 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/06 22:19:43 by hdeniz           ###   ########.fr       */
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

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ char	detect_case(register char compare);
/* *************************** [^] PROTOTYPES [^] *************************** */

bool
	ft_strcasecmp(const char *const string, const char *const compare)
{
	register size_t	index;

	if (string == compare)
		return (true);
	if (!string || !compare)
		return (false);
	index = 0;
	while (!!string[index] && !!compare[index] && \
		((string[index] + detect_case(string[index])) == \
		(compare[index] + detect_case(compare[index]))))
		++index;
	if (!compare[index] && !string[index])
		return (true);
	return (false);
}

extern __inline__ char
	detect_case(register char compare)
{
	if (compare >= 'A' && compare <= 'Z')
		return (32);
	return (0);
}
