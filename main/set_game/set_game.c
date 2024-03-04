/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:42:40 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/08 17:42:42 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../minilibx/mlx.h" /*
#   void *mlx_new_window(void *, int, int, char const *);
#   void *mlx_new_image(void *, int, int);
#   char *mlx_get_data_addr(void *, int *, int *, int *);
*/
#include "../../libft/libft.h" /*
#    int ft_strlen(char *);
#    int ft_matrixrlen(char **);
*/
#include "../cub3D.h" /*
# define SPEED ?
# define WINDOW_WIDTH ?
# define WINDOW_HEIGHT ?
# define PLAYER_SPEED ?
#typedef t_game;
#   void game_error(t_game, char *, char);
#    int search_in_map(char **, char, char);
#   void set_walls_as_objects(t_game);
#   void set_coins_as_objects(t_game);
#   void load_textures(t_game);
#   void set_map_textures(t_game);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static char	*get_title(char **argv);
static void	set_player_struct(t_game game);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	set_game(t_game game, char **argv)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		game_error(game, " ERROR - MLX failed to build\n", 1);
	game->window_title = get_title(argv);
	game->window = mlx_new_window(\
		game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, \
		game->window_title);
	if (!game->window)
		game_error(game, " ERROR - Window failed to build\n", 2);
	set_player_struct(game);
}

static void
	set_player_struct(t_game game)
{
	game->object.player.x = 0; // HERE
	game->object.player.y = 0; // HERE
	game->object.player.target_x = 0.0; // HERE
	game->object.player.target_y = 0.0; // HERE
	game->object.player.angle = 0.0F; // HERE
	game->object.player.angle_target_x = 0.0F; // HERE
	game->object.player.angle_target_y = 0.0F; // HERE
	game->object.player.key_movement[0] = 0;
	game->object.player.key_movement[1] = 0;
	game->object.player.key_movement[2] = 0;
	game->object.player.key_movement[3] = 0;
	game->object.player.key_rotation[0] = 0;
	game->object.player.key_rotation[1] = 0;
	game->object.player.key_rotation[2] = 0;
	game->object.player.key_rotation[3] = 0;
}

static char
	*get_title(char **argv)
{
	register int	eax;

	if (!argv[1])
		return ("[Random Map]");
	eax = ft_strlen(argv[1]) - 1;
	while ((eax > 0) && (argv[1][eax] != '/') && (argv[1][eax] != '\\'))
		--eax;
	return (argv[1] + eax + (eax != 0));
}
