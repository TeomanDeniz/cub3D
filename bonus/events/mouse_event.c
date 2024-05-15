/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:40:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/04/20 14:40:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../cub3D.h" /*
# define ROTATE_SPEED
# define WALL_SIZE
#typedef t_game;
#        */
#include "../../minilibx/mlx.h" /*
#    int mlx_mouse_move(void *, int , int);
#    int mlx_mouse_get_pos(void *, int *, int *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	check_y_position(t_game game, register int old_y, \
register int y);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	mouse_event(t_game game)
{
	static int		old_x = -1;
	static int		old_y = -1;
	int				x;
	int				y;

	mlx_mouse_get_pos(game->window, &x, &y);
	if (old_x == -1 || old_y == -1)
	{
		old_x = x;
		old_y = y;
		return ;
	}
	if (old_x != x)
	{
		game->theta_target_rotation += (float)(x - old_x) / \
			(float)(20000.0F * ROTATE_SPEED);
	}
	check_y_position(game, old_y, y);
	mlx_mouse_move(game->window, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	mlx_mouse_get_pos(game->window, &x, &y);
	old_x = x;
	old_y = y;
}

extern __inline__ void
	check_y_position(t_game game, register int old_y, register int y)
{
	register int	new_y;

	new_y = (float)(y - old_y) / (float)(ROTATE_SPEED * 15);
	if (new_y < 0 && game->target_skyline < (float)WALL_SIZE * 2.0F)
	{
		game->target_skyline += -(float)(y - old_y) / \
			(float)(ROTATE_SPEED * 12);
	}
	if (new_y > 0 && game->target_skyline > 0.0F)
	{
		game->target_skyline -= (float)(y - old_y) / \
			(float)(ROTATE_SPEED * 12);
	}
}
