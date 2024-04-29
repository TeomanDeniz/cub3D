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
/* **************************** [^] INCLUDES [^] **************************** */

void
	skybox(t_game game, register int ground, register int floor)
{
	register int	x;
	register int	y;

	y = 0;
	while (y < (int)game->skyline)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			putpixel(game, x, y, (unsigned)floor);
			++x;
		}
		++y;
	}
	y = (int)game->skyline;
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
