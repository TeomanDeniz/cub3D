/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_events.c                                     :+:      :+:    :+:   */
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
# define ROTATE_SPEED
# define PLAYER_SPEED
# define SLICE
#typedef t_game;
#   void mouse_event(t_game);
#        */
#include "../../libft/ft_math/ft_math.h" /*
# define M_PIX2_F
#  float ft_lerpf(float, float, float);
#  float ft_sinf(float);
#  float ft_cosf(float);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	rotation_handle(t_game game);
extern __inline__ void	movement_handle(t_game game);
extern __inline__ void	door_handle(t_game game);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	input_events(t_game game)
{
	movement_handle(game);
	mouse_event(game);
	rotation_handle(game);
	door_handle(game);
}

extern __inline__ void
	movement_handle(t_game game)
{
	if (game->key.s)
	{
		game->target_x -= game->cos_theta_rotation;
		game->target_y += -game->sin_theta_rotation;
	}
	if (game->key.w)
	{
		game->target_x += game->cos_theta_rotation;
		game->target_y -= -game->sin_theta_rotation;
	}
	if (game->key.d)
	{
		game->target_x += -game->sin_theta_rotation;
		game->target_y += game->cos_theta_rotation;
	}
	if (game->key.a)
	{
		game->target_x -= -game->sin_theta_rotation;
		game->target_y -= game->cos_theta_rotation;
	}
	collision(game);
	game->x = ft_lerpf(game->x, game->target_x, SLICE);
	game->y = ft_lerpf(game->y, game->target_y, SLICE);
}

extern __inline__ void
	rotation_handle(t_game game)
{
	if (game->theta_rotation < 0.0F)
	{
		game->theta_rotation += M_PIX2_F;
		game->theta_target_rotation += M_PIX2_F;
	}
	if (game->theta_rotation > M_PIX2_F)
	{
		game->theta_rotation -= M_PIX2_F;
		game->theta_target_rotation -= M_PIX2_F;
	}
	if (game->key.arrow_l)
		game->theta_target_rotation -= ROTATE_SPEED;
	if (game->key.arrow_r)
		game->theta_target_rotation += ROTATE_SPEED;
	if (game->target_skyline < (float)WALL_SIZE * 2.0F && game->key.arrow_u)
		game->target_skyline += WINDOW_HEIGHT * ROTATE_SPEED;
	if (game->target_skyline > 0.0F && game->key.arrow_d)
		game->target_skyline -= WINDOW_HEIGHT * ROTATE_SPEED;
	game->skyline = ft_lerpf(game->skyline, game->target_skyline, SLICE);
	game->theta_rotation = ft_lerpf(game->theta_rotation, \
		game->theta_target_rotation, SLICE);
	game->cos_theta_rotation = (ft_cosf(game->theta_rotation) / 32.0F) \
		* PLAYER_SPEED;
	game->sin_theta_rotation = (ft_sinf(game->theta_rotation) / 32.0F) \
		* PLAYER_SPEED;
}

extern __inline__ void
	door_handle(t_game game)
{
	if (game->key.space)
	{
		game->key.space = 0U;
		if ((int)game->x + 1 < game->map_width && (int)game->x - 1 > 0 && \
			(int)game->y + 1 < game->map_height && (int)game->y - 1 > 0)
		{
			if (game->map[(int)game->y + 1][(int)game->x] == 'D')
				game->map[(int)game->y + 1][(int)game->x] = 'C';
			else if (game->map[(int)game->y][(int)game->x + 1] == 'D')
				game->map[(int)game->y][(int)game->x + 1] = 'C';
			else if (game->map[(int)game->y - 1][(int)game->x] == 'D')
				game->map[(int)game->y - 1][(int)game->x] = 'C';
			else if (game->map[(int)game->y][(int)game->x - 1] == 'D')
				game->map[(int)game->y][(int)game->x - 1] = 'C';
			else if (game->map[(int)game->y + 1][(int)game->x] == 'C')
				game->map[(int)game->y + 1][(int)game->x] = 'D';
			else if (game->map[(int)game->y][(int)game->x + 1] == 'C')
				game->map[(int)game->y][(int)game->x + 1] = 'D';
			else if (game->map[(int)game->y - 1][(int)game->x] == 'C')
				game->map[(int)game->y - 1][(int)game->x] = 'D';
			else if (game->map[(int)game->y][(int)game->x - 1] == 'C')
				game->map[(int)game->y][(int)game->x - 1] = 'D';
		}
	}
}
