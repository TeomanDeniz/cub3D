/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:40:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/04/20 14:40:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../cub3D.h" /*
# define MAP_GRID_SIZE
#typedef t_game;
#   void putpixel(t_game, int, int, int);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	draw_grid(t_game game, register int x, register int y, \
register unsigned int color);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	minimap(t_game game, register int x, register int y)
{
	while (++y, y < 3)
	{
		x = -3;
		while (++x, x < 3)
		{
			draw_grid(game, x + 2, y + 2, 0X000000U);
			if (((int)game->x + x) < game->map_width && \
				((int)game->x + x) >= 0 && ((int)game->y + y) < \
				game->map_height && ((int)game->y + y) >= 0)
			{
				if (game->map[(int)game->y + y][(int)game->x + x] == '1')
					draw_grid(game, x + 2, y + 2, 0X222222U);
				if (game->map[(int)game->y + y][(int)game->x + x] == 'D')
					draw_grid(game, x + 2, y + 2, 0X882222U);
				if (game->map[(int)game->y + y][(int)game->x + x] == 'C')
					draw_grid(game, x + 2, y + 2, 0X777788U);
				if (game->map[(int)game->y + y][(int)game->x + x] == '0')
					draw_grid(game, x + 2, y + 2, 0XFFFFFFU);
				if (x == 0 && y == 0)
					draw_grid(game, 2, 2, 0XFF0000U);
			}
		}
	}
}

extern __inline__ void
	draw_grid(t_game game, register int x, register int y, \
register unsigned int color)
{
	register int	index_x;
	register int	index_y;

	x *= MAP_GRID_SIZE;
	y *= MAP_GRID_SIZE;
	index_y = 19;
	while (++index_y, index_y < MAP_GRID_SIZE + 20)
	{
		index_x = 19;
		while (++index_x, index_x < MAP_GRID_SIZE + 20)
			putpixel(game, index_x + x, index_y + y, color);
	}
}
