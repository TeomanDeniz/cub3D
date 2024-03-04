/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:49:34 by hdeniz            #+#    #+#             */
/*   Updated: 2023/09/03 18:49:35 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../so_long.h" /*
# define SPEED ?
# define SLICE ?
# define PLAYER_SPEED ?
# define PLAYER_WIDTH ?
# define PLAYER_HEIGHT ?
#typedef t_game;
*/
#include "../../libft/ft_math/ft_math.h" /*
# double ft_lerp(double, double, double);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static char	barrier_hit_yu(t_game game);
static char	barrier_hit_xl(t_game game);
static char	barrier_hit_yd(t_game game);
static char	barrier_hit_xr(t_game game);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	player_position(t_game game)
{
	if (game->object.player.position[0] && !barrier_hit_yd(game))
		game->object.player.target_y += PLAYER_SPEED;
	if (game->object.player.position[1] && !barrier_hit_yu(game))
		game->object.player.target_y -= PLAYER_SPEED;
	if (game->object.player.position[2] && !barrier_hit_xl(game))
		game->object.player.target_x -= PLAYER_SPEED;
	if (game->object.player.position[3] && !barrier_hit_xr(game))
		game->object.player.target_x += PLAYER_SPEED;
	game->object.player.x = ft_lerp(game->object.player.x, \
		game->object.player.target_x, SLICE);
	game->object.player.y = ft_lerp(game->object.player.y, \
		game->object.player.target_y, SLICE);
}

static char
	barrier_hit_yu(t_game game)
{
	register int	ecx;
	register double	movement;

	movement = game->object.player.target_y;
	ecx = -1;
	while (++ecx, ecx < game->object.number_of_barriers)
	{
		if (movement <= game->object.barrier[ecx].end_y && \
			(game->object.player.y > game->object.barrier[ecx].end_y - \
			(PLAYER_SPEED + 1)) && ((game->object.player.x + PLAYER_WIDTH) >= \
			game->object.barrier[ecx].start_x && game->object.player.x <= \
			game->object.barrier[ecx].end_x))
		{
			game->object.player.target_y = game->object.player.y;
			return (1);
		}
	}
	return (0);
}

static char
	barrier_hit_xl(t_game game)
{
	register int	ecx;
	register double	movement;

	movement = game->object.player.target_x;
	ecx = -1;
	while (++ecx, ecx < game->object.number_of_barriers)
	{
		if (movement <= game->object.barrier[ecx].end_x && \
			(game->object.player.x > game->object.barrier[ecx].end_x - \
			(PLAYER_SPEED + 1)) && ((game->object.player.y + PLAYER_HEIGHT) >= \
			game->object.barrier[ecx].start_y && game->object.player.y <= \
			game->object.barrier[ecx].end_y))
		{
			game->object.player.target_x = game->object.player.x;
			return (1);
		}
	}
	return (0);
}

static char
	barrier_hit_yd(t_game game)
{
	register int	ecx;
	register double	movement;

	movement = game->object.player.target_y;
	ecx = -1;
	while (++ecx, ecx < game->object.number_of_barriers)
	{
		if ((movement + PLAYER_HEIGHT) >= game->object.barrier[ecx].start_y && \
			((game->object.player.y + PLAYER_HEIGHT) < \
			game->object.barrier[ecx].start_y + (PLAYER_SPEED + 1)) && \
			((game->object.player.x + PLAYER_WIDTH) >= \
			game->object.barrier[ecx].start_x && game->object.player.x <= \
			game->object.barrier[ecx].end_x))
		{
			game->object.player.target_y = game->object.player.y;
			return (1);
		}
	}
	return (0);
}

static char
	barrier_hit_xr(t_game game)
{
	register int	ecx;
	register double	movement;

	movement = game->object.player.target_x;
	ecx = -1;
	while (++ecx, ecx < game->object.number_of_barriers)
	{
		if ((movement + PLAYER_WIDTH) >= game->object.barrier[ecx].start_x && \
			((game->object.player.x + PLAYER_WIDTH) < \
			game->object.barrier[ecx].start_x + (PLAYER_SPEED + 1)) && \
			((game->object.player.y + PLAYER_HEIGHT) >= \
			game->object.barrier[ecx].start_y && game->object.player.y <= \
			game->object.barrier[ecx].end_y))
		{
			game->object.player.target_x = game->object.player.x;
			return (1);
		}
	}
	return (0);
}
