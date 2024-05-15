/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:36:16 by hdeniz            #+#    #+#             */
/*   Updated: 2024/05/15 01:22:?? by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int
	ft_atoi(const char *const string)
{
	register int			index;
	register unsigned int	sign;
	int						result;

	if (!string)
		return (0);
	index = 0;
	while (string[index] == ' ' || \
		string[index] == '\t' || string[index] == '\v' || \
		string[index] == '\f' || string[index] == '\r')
		++index;
	sign = 0;
	if (string[index] == '-' || string[index] == '+')
	{
		if (string[index] == '-')
			sign = 1;
		++index;
	}
	--index;
	result = 0;
	while (++index, string[index] >= '0' && string[index] <= '9')
		result = (result * 10) + (string[index] & 15);
	if (sign)
		result = (~(result) + 1);
	return (result);
}
