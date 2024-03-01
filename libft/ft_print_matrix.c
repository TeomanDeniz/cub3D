/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:06:38 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/17 14:06:39 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include <unistd.h> /*
#ssize_t write(int, const void *, size_t);
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	ft_print_matrix(char **matrix)
{
	register int	x;
	register int	y;

	y = -1;
	while (++y, matrix[y])
	{
		x = -1;
		while (++x, matrix[y][x])
			write(1, &matrix[y][x], 1);
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

void
	ft_print_matrix_fd(char **matrix, int fd)
{
	register int	x;
	register int	y;

	y = -1;
	while (++y, matrix[y])
	{
		x = -1;
		while (++x, matrix[y][x])
			write(fd, &matrix[y][x], 1);
		write(fd, "\n", 1);
	}
	write(fd, "\n", 1);
}
