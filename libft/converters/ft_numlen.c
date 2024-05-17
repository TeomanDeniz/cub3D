/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:10:11 by hdeniz            #+#    #+#             */
/*   Updated: 2024/05/17 16:21:00 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int
	ft_numlen(register int number)
{
	int	result;

	if (number < 0)
		number = ((~number) + 1);
	if (number < 10)
		return (1);
	result = -1;
	while (++result, number)
		number /= 10;
	return (result);
}
