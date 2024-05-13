/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_distance_y.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:40:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/04/20 14:40:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../cub3D.h" /*
#typedef t_game;
#typedef t_lidar;
#        */
#include <math.h> /*
#  float sqrtf(float);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	calculate_distance_y(t_game game, t_lidar lidar, int hit)
{
	game->ray[lidar.index].hit = hit;
	game->ray[lidar.index].x = lidar.x;
	game->ray[lidar.index].y = lidar.y_jump_on_map;
	game->ray[lidar.index].distance = \
		sqrtf((lidar.x - game->x) * (lidar.x - game->x) + \
		(lidar.y_jump_on_map - game->y) * (lidar.y_jump_on_map - game->y));
	return (1);
}
