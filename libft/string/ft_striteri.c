/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:22:32 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:22:34 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
#typedef size_t;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	ft_striteri(const char *const string, \
void (*function)(unsigned int, char *))
{
	register size_t	index;

	if (!string || !function)
		return ;
	index = 0;
	while (string[index])
	{
		function(index, &string[index]);
		++index;
	}
}
