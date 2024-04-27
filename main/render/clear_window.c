/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 07:24:49 by hdeniz            #+#    #+#             */
/*   Updated: 2024/03/08 07:24:50 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../cub3D.h" /*
# define DEFULT_WINDOW_Y_SIZE
# define DEFULT_WINDOW_X_SIZE
#typedef *t_game;
#   void putpixel(t_game, int, int, int);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	clear_window(t_game game)
{
	register int	x;
	register int	y;

	y = 0;
	while (y < (int)game->skyline)
	{
		x = 0;
		while (x < DEFULT_WINDOW_X_SIZE)
		{
			putpixel(game, x, y, 0X222222);
			++x;
		}
		++y;
	}
	y = (int)game->skyline;
	while (y < DEFULT_WINDOW_Y_SIZE)
	{
		x = 0;
		while (x < DEFULT_WINDOW_X_SIZE)
		{
			putpixel(game, x, y, 0X666666);
			++x;
		}
		++y;
	}
}
