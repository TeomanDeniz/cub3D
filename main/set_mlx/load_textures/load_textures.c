/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:37:54 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/19 15:37:55 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../so_long.h" /*
#typedef t_game;
#   void mlx_error(t_game, char *, char);
#   void *xpm_texture(t_game, char *);
#   void load_wall(t_game, int *);
#   void load_player(t_game, void *[?][?], int *);
#   void load_gate(t_game, void *[?], int *);
#   void load_coin(t_game, void *[?], int *);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* **************************** [V] CONSTANTS [V] *************************** */
#define FILE_GROUND "./textures/xpm/ground.xpm"
/* **************************** [^] CONSTANTS [^] *************************** */

void
	load_textures(t_game game_library)
{
	int	*z;

	z = &(int){0};
	load_player(game_library, game_library->texture_pack.player, z);
	load_wall(game_library, z);
	load_coin(game_library, game_library->texture_pack.coin, z);
	load_gate(game_library, game_library->texture_pack.gate, z);
	game_library->texture_pack.ground = xpm_texture(game_library, FILE_GROUND);
	++*z;
	if (!(game_library->texture_pack.ground))
		free_textures(game_library, *z);
}
