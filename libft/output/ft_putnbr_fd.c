/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:25:00 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:26:11 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../libft.h" /*
#   void ft_putchar_fd(int);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	ft_putnbr_fd(register int number, register int fd)
{
	register long	__number__;

	__number__ = number;
	if (__number__ < 0)
	{
		ft_putchar_fd('-', fd);
		__number__ = (~__number__) + 1;
	}
	if (__number__ < 10)
		ft_putchar_fd(__number__ + 48, fd);
	if (__number__ > 9)
	{
		ft_putnbr_fd(__number__ / 10, fd);
		ft_putnbr_fd(__number__ % 10, fd);
	}
}
