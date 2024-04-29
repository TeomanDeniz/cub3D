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
# define WINDOW_HEIGHT
# define WALL_SIZE
# define ROTATE_SPEED
# define PLAYER_SPEED
# define SLICE
#typedef t_game;
#   void putpixel(t_game, int, int, uint);
#*/
#include <stdlib.h> /*
#typedef size_t;
#*/
#include "../../libft/ft_math/ft_math.h" /*
#  float ft_lerpf(float, float, float);
#*/
#include <math.h>
#include "../../minilibx/mlx.h"
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	rotation_handle(t_game game);
extern __inline__ void	movement_handle(t_game game);
extern __inline__ void	handle(t_game game);
/* *************************** [^] PROTOTYPES [^] *************************** */

extern __inline__ int
	int_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void
	render(t_game game)
{
	register size_t	index;
	register int	left_to_right;
	register int	y;
	register int	x;
	register float	render;

	index = -1;
	handle(game);
	while (++index, index < game->number_of_rays)
	{
		render = fmin(WALL_SIZE + ft_fabsf(game->skyline - WINDOW_HEIGHT / 2), WALL_SIZE / game->ray[index].distance) * (game->ray[index].distance != 0.0);
		left_to_right = (int)(((float)index) * game->wall_pixel_width);
		x = -1;
		while (++x, x < game->wall_pixel_width)
		{
			y = 0;
			while ((int)(((float)y) < render))
			{
				putpixel(game, left_to_right + x, game->skyline - y, int_max(0XFFFFFF - ((((int)(game->ray[index].distance * 40)) << 8) + (((int)(game->ray[index].distance * 40)) << 16) + ((int)(game->ray[index].distance * 40))), 0));
				putpixel(game, left_to_right + x, game->skyline + y, int_max(0XFFFFFF - ((((int)(game->ray[index].distance * 40)) << 8) + (((int)(game->ray[index].distance * 40)) << 16) + ((int)(game->ray[index].distance * 40))), 0));
				++y;
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
	if (game->key[0]) // s
	{
		game->target_x -= game->sin_theta_rotation;
		game->target_y -= game->cos_theta_rotation;
	}
	if (game->key[1]) // w
	{
		game->target_x += game->sin_theta_rotation;
		game->target_y += game->cos_theta_rotation;
	}
	if (game->key[2]) // d
	{
		game->target_x += game->cos_theta_rotation;
		game->target_y -= game->sin_theta_rotation;
	}
	if (game->key[3]) // a
	{
		game->target_x -= game->cos_theta_rotation;
		game->target_y += game->sin_theta_rotation;
	}
	game->x = ft_lerpf(game->x, game->target_x, SLICE);
	game->y = ft_lerpf(game->y, game->target_y, SLICE);
}

extern __inline__ void
	rotation_handle(t_game game)
{
	if (game->key[4])
		game->target_skyline -= 30.0F;
	if (game->key[5])
		game->target_skyline += 30.0F;
	if (game->key[6])
		game->theta_target_rotation += ROTATE_SPEED;
	if (game->key[7])
		game->theta_target_rotation -= ROTATE_SPEED;
	game->skyline = ft_lerpf(game->skyline, game->target_skyline, SLICE);
	game->theta_rotation = ft_lerpf(game->theta_rotation, \
		game->theta_target_rotation, SLICE);
	if (game->theta_rotation < 0.0F)
	{
		game->theta_rotation = 6.3F;
		game->theta_target_rotation += 6.3F;
	}
	if (game->theta_rotation > 6.3F)
	{
		game->theta_rotation = 0.0F;
		game->theta_target_rotation -= 6.3F;
	}
	game->cos_theta_rotation = cosf(game->theta_rotation) / 32.0F;
	game->sin_theta_rotation = sinf(game->theta_rotation) / 32.0F;
}
