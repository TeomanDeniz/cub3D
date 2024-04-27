/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:36:16 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:36:19 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
#typedef bool;
# define false;
# define true;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	ft_atoi(const char *const string)
{
	register int	index;
	bool			sign;
	int				result;

	if (!string)
		return (0);
	index = 0;
	while (string[index] == ' ' || \
		string[index] == '\t' || string[index] == '\v' || \
		string[index] == '\f' || string[index] == '\r')
		++index;
	sign = false;
	if (string[index] == '-' || string[index] == '+')
	{
		if (string[index] == '-')
			sign = true;
		++index;
	}
	--index;
	while (++index, string[index] >= '0' && string[index] <= '9')
		result = (result * 10) + (string[index] & 15);
	if (sign)
		result = (~(result) + 1);
	return (result);
}
