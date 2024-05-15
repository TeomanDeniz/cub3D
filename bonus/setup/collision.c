/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
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
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	is_hit(t_game game, register float x, register float y);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	collision(t_game game)
{
	register float	dx;
	register float	dy;

	dx = game->target_x - game->x;
	dy = game->target_y - game->y;
	if (dx > 0.1F)
		dx = 0.1F;
	if (dy > 0.1F)
		dy = 0.1F;
	if (dx < -0.1F)
		dx = -0.1F;
	if (dy < -0.1F)
		dy = -0.1F;
	if (is_hit(game, game->x + dx, game->y))
		game->target_x = game->x;
	if (is_hit(game, game->x, game->y + dy))
		game->target_y = game->y;
}

extern __inline__ int
	is_hit(t_game game, register float x, register float y)
{
	if (x < 0.0F || x >= game->map_width || y < 0.0F || y >= game->map_height)
		return (1);
	return (game->map[(int)y][(int)x] == '1' || \
		game->map[(int)y][(int)x] == 'D');
}
