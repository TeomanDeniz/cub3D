/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lidar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:40:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/04/20 14:40:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../cub3D.h" /*
# define RAY_JUMP_LIMIT
#typedef t_game;
#typedef t_lidar;
#    int check_between_0_90(t_game, t_lidar *);
#    int check_between_90_180(t_game, t_lidar *);
#    int check_between_180_240(t_game, t_lidar *);
#    int check_between_240_360(t_game, t_lidar *);
#        */
#include "../../../libft/ft_math/ft_math.h" /*
# define M_PIX2_F
# define M_PIX2_3_F
# define M_PI_2
# define M_PI_F
#  float ft_cosf(float);
#  float ft_tanf(float);
#  float ft_floorf(float);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	setup_ray(t_game game, t_lidar *lidar);
extern __inline__ void	fix_seg_error(t_game game, t_lidar *lidar);
extern __inline__ int	ray_event(t_game game, t_lidar *lidar);
/* *************************** [^] PROTOTYPES [^] *************************** */

#include <stdio.h>

void
	lidar(t_game game)
{
	t_lidar	lidar;

	lidar.index = game->number_of_rays;
	lidar.mod_game_x = ft_fmodf(-game->x, 1.0F);
	lidar.mod_game_y = ft_fmodf(-game->y, 1.0F);
	while (--lidar.index, lidar.index >= 0)
	{
		setup_ray(game, &lidar);
		while (lidar.x_jump < RAY_JUMP_LIMIT && lidar.y_jump < RAY_JUMP_LIMIT)
		{
			lidar.x = (lidar.mod_game_y + lidar.y_jump) * lidar.x_tan + game->x;
			lidar.y = (lidar.mod_game_x + lidar.x_jump) * lidar.y_tan + game->y;
			if (lidar.x >= (float)game->map_width - 1)
				lidar.x = (float)game->map_width;
			if (lidar.y >= (float)game->map_height - 1)
				lidar.y = (float)game->map_height;
			lidar.x_jump_on_map = (lidar.x_jump + ft_floorf(game->x) + 1.0F);
			lidar.y_jump_on_map = (lidar.y_jump + ft_floorf(game->y) + 1.0F);
			fix_seg_error(game, &lidar);
			if (ray_event(game, &lidar))
				break ;
		}
		game->ray[lidar.index].distance *= game->ray[lidar.index].cos_theta;
	}
}

extern __inline__ int
	ray_event(t_game game, t_lidar *lidar)
{
	if (0.0F <= lidar->theta && lidar->theta < M_PI_2)
		if (check_between_0_90(game, lidar))
			return (1);
	if (M_PI_2 <= lidar->theta && lidar->theta < M_PI_F)
		if (check_between_90_180(game, lidar))
			return (1);
	if (M_PI_F <= lidar->theta && lidar->theta < M_PIX2_3_F)
		if (check_between_180_240(game, lidar))
			return (1);
	if (M_PIX2_3_F <= lidar->theta && lidar->theta <= M_PIX2_F)
		if (check_between_240_360(game, lidar))
			return (1);
	if (0.0F <= lidar->theta && lidar->theta < M_PI_F)
		lidar->y_jump = lidar->y_add;
	if (M_PI_F <= lidar->theta && lidar->theta < M_PIX2_F)
		lidar->y_jump = -(lidar->y_add + 1);
	if ((0.0F <= lidar->theta && lidar->theta < M_PI_2) || \
		(M_PIX2_3_F <= lidar->theta && \
		lidar->theta <= M_PIX2_F))
		lidar->x_jump = lidar->x_add;
	if (M_PI_2 < lidar->theta && lidar->theta <= M_PIX2_3_F)
		lidar->x_jump = -(lidar->x_add + 1);
	return (0);
}

extern __inline__ void
	fix_seg_error(t_game game, t_lidar *lidar)
{
	if (lidar->x < 0.0F)
		lidar->x = 0.1F;
	if (lidar->y < 0.0F)
		lidar->y = 0.1F;
	if (lidar->x >= (float)game->map_width)
		lidar->x = (float)game->map_width - 0.9F;
	if (lidar->y >= (float)game->map_height)
		lidar->y = (float)(game->map_height - 0.9F);
	if (lidar->y_jump_on_map < 0.0F)
		lidar->y_jump_on_map = 0.0F;
	if (lidar->x_jump_on_map < 0.0F)
		lidar->x_jump_on_map = 0.0F;
	if (lidar->y_jump_on_map >= (float)game->map_height)
		lidar->y_jump_on_map = (float)game->map_height - 1.0F;
	if (lidar->x_jump_on_map >= (float)game->map_width)
		lidar->x_jump_on_map = (float)game->map_width - 1.0F;
}

extern __inline__ void
	setup_ray(t_game game, t_lidar *lidar)
{
	game->ray[lidar->index].hit = 0;
	lidar->x = 0.0F;
	lidar->y = 0.0F;
	lidar->x_jump = 0;
	lidar->y_jump = 0;
	lidar->x_add = 0;
	lidar->y_add = 0;
	lidar->theta = game->ray[lidar->index].theta + game->theta_rotation;
	if (lidar->theta > M_PIX2_F)
		lidar->theta -= M_PIX2_F;
	else if (lidar->theta < 0.0F)
		lidar->theta += M_PIX2_F;
	if (M_PI_F <= lidar->theta && lidar->theta < M_PIX2_F)
		lidar->y_jump = -1;
	if (M_PI_2 < lidar->theta && lidar->theta < M_PIX2_3_F)
		lidar->x_jump = -1;
	lidar->y_tan = ft_tanf(lidar->theta);
	lidar->x_tan = 1.0F / lidar->y_tan;
}
