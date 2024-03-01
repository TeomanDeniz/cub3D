/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:39:57 by hdeniz            #+#    #+#             */
/*   Updated: 2023/09/04 13:39:58 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../so_long.h" /*
# define TILE_WIDTH ?
# define TILE_HEIGHT ?
# define PLAYER_WIDTH ?
# define PLAYER_HEIGHT ?
#    int close_window(t_game);
#typedef t_game;
*/
#include <unistd.h> /*
#ssize_t write(int, const void *, size_t);
*/
#include "../../libft/ft_math/ft_math.h" /*
# double ft_fabs(double);
# double ft_fmax(double, double);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static inline void	check_rotation_player(t_game game, double x, double y);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	game(t_game game)
{
	static double	old_x;
	static double	old_y;
	double			delta_x;
	double			delta_y;

	old_x = 0.0 + old_x;
	old_y = 0.0 + old_y;
	if (old_x == 0.0)
		old_x = game->object.player.x;
	if (old_y == 0.0)
		old_y = game->object.player.y;
	delta_x = (game->object.player.x - old_x) / TILE_WIDTH;
	delta_y = (game->object.player.y - old_y) / TILE_HEIGHT;
	check_rotation_player(game, delta_x, delta_y);
	game->steps += ft_fmax(ft_fabs(delta_x), ft_fabs(delta_y));
	old_x = game->object.player.x;
	old_y = game->object.player.y;
}

static inline void
	check_rotation_player(t_game game, double x, double y)
{
	if (y > 0.0 && ft_fabs(y) > ft_fabs(x))
		game->object.player.rotation = 0;
	if (y < 0.0 && ft_fabs(y) > ft_fabs(x))
		game->object.player.rotation = 1;
	if (x < 0.0 && ft_fabs(x) > ft_fabs(y))
		game->object.player.rotation = 2;
	if (x > 0.0 && ft_fabs(x) > ft_fabs(y))
		game->object.player.rotation = 3;
}
