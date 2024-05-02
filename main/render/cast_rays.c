/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:40:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/04/20 14:40:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../cub3D.h" /*
#typedef t_game;
#        */
#include "../../libft/ft_math/ft_math.h" /*
#  float ft_cosf(float);
#  float ft_sinf(float);
#        */
#include <stdlib.h> /*
#typedef size_t;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
extern __inline__ void	ray_going(t_game game, register size_t index);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	cast_rays(t_game game)
{
	register size_t	index;

	index = 0;
	while (index < game->number_of_rays)
	{
		game->ray[index].distance = 0.0;
		ray_going(game, index);
		game->ray[index].distance *= game->ray[index].cos_theta;
		++index;
	}
}

extern __inline__ void
	ray_going(t_game game, register size_t index)
{
	register float	ray_angle;
	register float	x;
	register float	y;

	while (1)
	{
		ray_angle = game->theta_rotation - game->ray[index].theta;
		x = game->ray[index].distance * ft_sinf(ray_angle) + game->x;
		y = game->ray[index].distance * ft_cosf(ray_angle) + game->y;
		if (x < 0.0F)
			x = 0.0F;
		if (y < 0.0F)
			y = 0.0F;
		if (x >= (float)game->map_weight)
			x = (float)game->map_weight - 1.0F;
		if (y >= (float)game->map_height)
			y = (float)game->map_height - 1.0F;
		if (game->map[(int)y][(int)x] == '1' || \
			game->map[(int)(y + 0.01F)][(int)x] == '1')
			return ;
		game->ray[index].distance += RENDER_EPSILON;
		putpixel(game, x * 10, y * 10, 0X6666FF);
	}
}
/*
extern __inline__ void
	teleport_rays(t_game game)
{
	register int	jump_x;
	register int	jump_y;
	register float	x;
	register float	y;
	register float	tan_rotation;

	jump_x = (fmodf(1.0F - game->y, 1.0F));
	jump_y = (fmodf(1.0F - game->x, 1.0F));
	tan_rotation = tanf(game->theta_rotation);
	while (1)
	{
		x = (jump_x * 1.0F / tan_rotation + game->x);
		y = (jump_y * tan_rotation + game->y);
		if (jump_y < x)
		{
			++jump_y;
		}
		else
		{
			++jump_x;
		}
	}
}*/
