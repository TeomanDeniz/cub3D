/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 07:24:49 by hdeniz            #+#    #+#             */
/*   Updated: 2024/03/08 07:24:50 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../cub3D.h" /*
# define WINDOW_WIDTH
# define WINDOW_HEIGHT
#typedef *t_game;
#   void putpixel(t_game, int, int, uint);
#        */
#include "../../libft/ft_math/ft_math.h" /*
#    int ft_imax(int, int);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	skybox(t_game game, register int ground, register int floor)
{
	register int	x;
	register int	y;

	y = -1;
	while (++y, y < (int)game->skyline && y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			putpixel(game, x, y, (unsigned)floor);
			++x;
		}
	}
	y = ft_imax((int)game->skyline, 0);
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			putpixel(game, x, y, (unsigned)ground);
			++x;
		}
		++y;
	}
}
