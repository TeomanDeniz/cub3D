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
#typedef t_lidar;
#        */
#include "../../libft/ft_math/ft_math.h" /*
#  float ft_cosf(float);
#  float ft_sinf(float);
#  float ft_sqrtf(float);
#  float ft_floorf(float);
#  float ft_fminf(float, float);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	lidar_setup(t_game game, t_lidar *lidar);
extern __inline__ void	throw_ray_start(t_game game, t_lidar *lidar);
extern __inline__ void	fix_seg_error(t_game game, t_lidar *lidar);
extern __inline__ void	ray_going(t_game game, t_lidar *lidar);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	cast_rays(t_game game)
{
	t_lidar	lidar;

	lidar.index = game->number_of_rays;
	while (--lidar.index, lidar.index >= 0)
	{
		lidar_setup(game, &lidar);
		while (lidar.ray_length < RENDER_DISTANCE)
		{
			ray_going(game, &lidar);
			fix_seg_error(game, &lidar);
			if (game->map[(int)game->ray[lidar.index].y] \
				[(int)game->ray[lidar.index].x] == '1' || \
				game->map[(int)(game->ray[lidar.index].y + 0.01F)] \
				[(int)game->ray[lidar.index].x] == '1')
				break ;
		}
		game->ray[lidar.index].distance = ft_fminf(RENDER_DISTANCE, \
			lidar.ray_length) * game->ray[lidar.index].cos_theta;
	}
}

extern __inline__ void
	ray_going(t_game game, t_lidar *lidar)
{
	if (lidar->x_distance < lidar->y_distance)
	{
		lidar->ray_length = lidar->x_distance;
		lidar->x_distance += lidar->jump_x;
		game->ray[lidar->index].x += lidar->add_x;
	}
	else if (lidar->x_distance > lidar->y_distance)
	{
		lidar->ray_length = lidar->y_distance;
		lidar->y_distance += lidar->jump_y;
		game->ray[lidar->index].y += lidar->add_y;
	}
	else
	{
		lidar->ray_length = lidar->x_distance;
		lidar->x_distance += lidar->jump_x;
		lidar->y_distance += lidar->jump_y;
		game->ray[lidar->index].x += lidar->add_x;
		game->ray[lidar->index].y += lidar->add_y;
	}
}

extern __inline__ void
	throw_ray_start(t_game game, t_lidar *lidar)
{
	if (0.0F > lidar->cos_theta)
	{
		lidar->add_x = -1.0F;
		lidar->x_distance = lidar->jump_x * \
			(lidar->x_start - game->ray[lidar->index].x);
	}
	if (0.0F < lidar->cos_theta)
		lidar->add_x = 1.0F;
	if (0.0F < lidar->cos_theta)
		lidar->x_distance = lidar->jump_x * \
			(1.0F + game->ray[lidar->index].x - lidar->x_start);
	if (0.0F > lidar->sin_theta)
		lidar->add_y = -1.0F;
	if (0.0F > lidar->sin_theta)
		lidar->y_distance = lidar->jump_y * \
			(lidar->y_start - game->ray[lidar->index].y);
	if (0.0F < lidar->sin_theta)
		lidar->add_y = 1.0F;
	if (0.0F < lidar->sin_theta)
		lidar->y_distance = lidar->jump_y * \
			(1.0F + game->ray[lidar->index].y - lidar->y_start);
}

extern __inline__ void
	fix_seg_error(t_game game, t_lidar *lidar)
{
	if (game->ray[lidar->index].x < 0.0F)
		game->ray[lidar->index].x = 0.0F;
	if (game->ray[lidar->index].y < 0.0F)
		game->ray[lidar->index].y = 0.0F;
	if (game->ray[lidar->index].x >= (float)game->map_width)
		game->ray[lidar->index].x = (float)game->map_width - 1.0F;
	if (game->ray[lidar->index].y >= (float)game->map_height)
		game->ray[lidar->index].y = (float)game->map_height - 1.0F;
}

extern __inline__ void
	lidar_setup(t_game game, t_lidar *lidar)
{
	lidar->add_x = 0;
	lidar->add_y = 0;
	lidar->cos_theta = ft_cosf(game->theta_rotation + \
		game->ray[lidar->index].theta);
	lidar->sin_theta = -ft_sinf(game->theta_rotation + \
		game->ray[lidar->index].theta);
	lidar->ray_length = 0;
	lidar->x_start = game->x;
	lidar->y_start = game->y;
	lidar->x_distance = 0;
	lidar->y_distance = 0;
	lidar->jump_x = (float)(ft_sqrtf(1.0F + \
		(lidar->sin_theta / lidar->cos_theta) * \
		(lidar->sin_theta / lidar->cos_theta)));
	lidar->jump_y = (float)(ft_sqrtf(1.0F + \
		(lidar->cos_theta / lidar->sin_theta) * \
		(lidar->cos_theta / lidar->sin_theta)));
	game->ray[lidar->index].x = (unsigned char)(ft_floorf(lidar->x_start));
	game->ray[lidar->index].y = (unsigned char)(ft_floorf(lidar->y_start));
	lidar->add_x = 0.0F;
	lidar->add_y = 0.0F;
	throw_ray_start(game, lidar);
}
