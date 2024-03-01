/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:25:00 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/22 15:33:11 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include <unistd.h> /*
#ssize_t write(int, const void *, size_t);
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	ft_putnbr(register int number)
{
	char	character;

	if (number < 0)
		number = (write(1, "-", 1), (number * -1));
	if (number < 10)
	{
		character = number | 0X30;
		write(1, &character, 1);
	}
	if (number > 9)
		(ft_putnbr(number / 10), ft_putnbr(number % 10));
}
