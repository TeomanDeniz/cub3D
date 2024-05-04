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
/* **************************** [^] INCLUDES [^] **************************** */

#include <math.h>

void
	cast_rays(t_game game)
{
	register int index;

	index = 0;
	while (index < game->number_of_rays)
	{
		float cell_step_x = 0;
		float cell_step_y = 0;
		float ray_direction_x = cos(game->theta_rotation + game->ray[index].theta);
		float ray_direction_y = -sin(game->theta_rotation + game->ray[index].theta);
		float ray_length = 0;
		float ray_start_x = game->x;
		float ray_start_y = game->y;
		float x_ray_length = 0;
		float y_ray_length = 0;
		float x_ray_unit_length = (float)(sqrt(1 + (ray_direction_y / ray_direction_x) * (ray_direction_y / ray_direction_x)));
		float y_ray_unit_length = (float)(sqrt(1 + (ray_direction_x / ray_direction_y) * (ray_direction_x / ray_direction_y)));

		game->ray[index].x = (unsigned char)(floor(ray_start_x));
		game->ray[index].y = (unsigned char)(floor(ray_start_y));
		if (0 > ray_direction_x)
		{
			cell_step_x = -1;
			x_ray_length = x_ray_unit_length * (ray_start_x - game->ray[index].x);
		}
		else if (0 < ray_direction_x)
		{
			cell_step_x = 1;

			x_ray_length = x_ray_unit_length * (1 + game->ray[index].x - ray_start_x);
		}
		else
			cell_step_x = 0;
		if (0 > ray_direction_y)
		{
			cell_step_y = -1;

			y_ray_length = y_ray_unit_length * (ray_start_y - game->ray[index].y);
		}
		else if (0 < ray_direction_y)
		{
			cell_step_y = 1;

			y_ray_length = y_ray_unit_length * (1 + game->ray[index].y - ray_start_y);
		}
		else
			cell_step_y = 0;
		while (ray_length < RENDER_DISTANCE)
		{
			if (x_ray_length < y_ray_length)
			{
				ray_length = x_ray_length;
				x_ray_length += x_ray_unit_length;

				game->ray[index].x += cell_step_x;
			}
			else if (x_ray_length > y_ray_length)
			{
				ray_length = y_ray_length;
				y_ray_length += y_ray_unit_length;

				game->ray[index].y += cell_step_y;
			}
			else
			{
				ray_length = x_ray_length;
				x_ray_length += x_ray_unit_length;
				y_ray_length += y_ray_unit_length;
				game->ray[index].x += cell_step_x;
				game->ray[index].y += cell_step_y;
			}
			if (game->ray[index].x < 0.0F)
				game->ray[index].x = 0.0F;
			if (game->ray[index].y < 0.0F)
				game->ray[index].y = 0.0F;
			if (game->ray[index].x >= (float)game->map_width)
				game->ray[index].x = (float)game->map_width - 1.0F;
			if (game->ray[index].y >= (float)game->map_height)
				game->ray[index].y = (float)game->map_height - 1.0F;
			if (game->map[(int)game->ray[index].y][(int)game->ray[index].x] == '1' || \
				game->map[(int)(game->ray[index].y + 0.01F)][(int)game->ray[index].x] == '1')
			{
				game->ray[index].distance = ft_fminf(RENDER_DISTANCE, ray_length) * game->ray[index].cos_theta;
				break ;
			}
		}
		++index;
	}
}
