/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 07:26:06 by hdeniz            #+#    #+#             */
/*   Updated: 2024/03/08 07:26:07 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../cub3D.h" /*
# define DEFULT_WINDOW_Y_SIZE
# define DEFULT_WINDOW_X_SIZE
# define WALL_SIZE
# define ROTATE_SPEED
# define PLAYER_SPEED
# define SLICE
#typedef t_game;
#   void putpixel(t_game, int, int, int);
#*/
#include <stdlib.h> /*
#typedef size_t;
#*/
#include "../../libft/ft_math/ft_math.h" /*
# define M_PI
# double ft_lerp(double, double, double);
#*/
#include <math.h>
#include "../../minilibx/mlx.h"
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	rotation_handle(t_game game);
extern __inline__ void	movement_handle(t_game game);
extern __inline__ void	handle(t_game game);
/* *************************** [^] PROTOTYPES [^] *************************** */

int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void
	render(t_game game)
{
	register size_t	index;
	register int	column;
	register int	wall;
	register int	spaces;

	index = -1;
	handle(game);

	while (++index, index < game->photon_len)
	{
		column = (int)((double)index * game->wall_pixel_size);
		spaces = -1;
		while (++spaces, spaces < game->wall_pixel_size)
		{
			wall = 0;
			while (wall < WALL_SIZE - game->photon[index].distance)
			{
				putpixel(game, column + spaces, (wall / game->photon[index].distance) + (game->skyline), max(0XFFFFFF - ((((int)(game->photon[index].distance * 40)) << 8) + (((int)(game->photon[index].distance * 40)) << 16) + ((int)(game->photon[index].distance * 40))), 0));
				putpixel(game, column + spaces, -(wall / game->photon[index].distance) + (game->skyline), max(0XFFFFFF - ((((int)(game->photon[index].distance * 40)) << 8) + (((int)(game->photon[index].distance * 40)) << 16) + ((int)(game->photon[index].distance * 40))), 0));
				++wall;
			}
		}
	}
}

extern __inline__ void
	handle(t_game game)
{
	movement_handle(game);
	rotation_handle(game);
}

extern __inline__ void
	movement_handle(t_game game)
{
	if (game->move[0]) // s
	{
		game->target_player_x -= game->sin_angle;
		game->target_player_y -= game->cos_angle;
	}
	if (game->move[1]) // w
	{
		game->target_player_x += game->sin_angle;
		game->target_player_y += game->cos_angle;
	}
	if (game->move[3]) // a
	{
		game->target_player_x -= game->cos_angle;
		game->target_player_y += game->sin_angle;
	}
	if (game->move[2]) // d
	{
		game->target_player_x += game->cos_angle;
		game->target_player_y -= game->sin_angle;
	}
	game->player_x = ft_lerp(game->player_x, game->target_player_x, SLICE);
	game->player_y = ft_lerp(game->player_y, game->target_player_y, SLICE);
}

extern __inline__ void
	rotation_handle(t_game game)
{
	if (game->move[4])
		game->target_skyline -= 30.0;
	if (game->move[5])
		game->target_skyline += 30.0;
	if (game->move[6])
		game->target_rotate += ROTATE_SPEED;
	if (game->move[7])
		game->target_rotate -= ROTATE_SPEED;
	game->rotate = ft_lerp(game->rotate, game->target_rotate, SLICE);
	game->skyline = ft_lerp(game->skyline, game->target_skyline, SLICE);
	if (game->rotate < 0.0)
	{
		game->rotate = 360.0;
		game->target_rotate += 360;
	}
	if (game->rotate > 360.0)
	{
		game->rotate = 0.0;
		game->target_rotate -= 360;
	}
	game->rotate_angle = game->rotate * (M_PI / 180.0) + 0.0001;
	game->cos_angle = cos(game->rotate_angle) / 32;
	game->sin_angle = sin(game->rotate_angle) / 32;
}
