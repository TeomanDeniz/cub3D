/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_between_0_90.c                               :+:      :+:    :+:   */
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
#    int calculate_distance_x(t_game, t_lidar, int);
#    int calculate_distance_y(t_game, t_lidar, int);
#        */
#include "../../../libft/ft_math/ft_math.h" /*
# define M_PI_F
#    int ft_imax(int, int);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	check_between_0_90(t_game game, t_lidar *lidar)
{
	if (lidar->x_jump_on_map < lidar->x)
	{
		if (game->map[(int)lidar->y][ft_imax(lidar->x_jump_on_map, \
			0)] == 'D' && calculate_distance_x(game, *lidar, 5))
			return (1);
		else if (game->map[(int)lidar->y][ft_imax(lidar->x_jump_on_map, \
			0)] == '1' && calculate_distance_x(game, *lidar, 1))
			return (1);
		else
			lidar->x_add++;
	}
	else
	{
		if (game->map[ft_imax(lidar->y_jump_on_map, 0)][ft_imax(\
			(int)lidar->x, 0)] == 'D' && calculate_distance_y(game, *lidar, 6))
			return (1);
		else if (game->map[ft_imax(lidar->y_jump_on_map, 0)][ft_imax(\
			(int)lidar->x, 0)] == '1' && calculate_distance_y(game, *lidar, 2))
			return (1);
		else
			lidar->y_add++;
	}
	return (0);
}
