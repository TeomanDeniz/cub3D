/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:50:21 by hdeniz            #+#    #+#             */
/*   Updated: 2023/09/04 12:30:15 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../so_long.h" /*
# define DEBUG ?
#typedef t_game;
*/
#include "../../libft/libft.h" /*
#    int ft_numlen(int);
#   void ft_putnbr(int);
*/
#include <unistd.h> /*
#ssize_t write(int, const void *, size_t);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static inline int		calculate_out_size(t_game game);
static inline void	clear_path_char(register int out_size);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	debug(t_game game)
{
	register int	out_size;

	out_size = calculate_out_size(game);
	clear_path_char(out_size);
	if (DEBUG)
	{
		write(1, "  X: ", 5);
		ft_putnbr((int)game->object.player.x);
		write(1, "  Y: ", 5);
		ft_putnbr((int)game->object.player.y);
		write(1, "  p[0]: ", 6);
		ft_putnbr((int)game->object.player.position[0]);
		write(1, "  p[1]: ", 6);
		ft_putnbr((int)game->object.player.position[1]);
		write(1, "  p[2]: ", 6);
		ft_putnbr((int)game->object.player.position[2]);
		write(1, "  p[3]: ", 6);
		ft_putnbr((int)game->object.player.position[3]);
	}
	write(1, "  Steps: ", 9);
	ft_putnbr((int)game->steps);
}

static inline void
	clear_path_char(register int out_size)
{
	register int	ecx;

	ecx = -1;
	while (++ecx, ecx <= out_size)
		write(1, "\b", 1);
	ecx = -1;
	while (++ecx, ecx <= out_size)
		write(1, " ", 1);
	ecx = -1;
	while (++ecx, ecx <= out_size)
		write(1, "\b", 1);
}

static inline int
	calculate_out_size(t_game game)
{
	int	out_size;

	out_size = 0;
	if (DEBUG)
	{
		out_size += 10 + 24;
		out_size += ft_numlen(game->object.player.x) + 1;
		out_size += ft_numlen(game->object.player.y) + 1;
	}
	return (out_size + 3 + 3 + 7);
}
