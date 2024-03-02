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
static inline char	*get_title(char **argv);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	set_game(t_game game_library, char **argv)
{
	game_library->mlx = mlx_init();
	if (!game_library->mlx)
		game_error(game_library, " ERROR - MLX failed to build\n", 1);
	game_library->window_title = get_title(argv);
	game_library->window = mlx_new_window(\
		game_library->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, \
		game_library->window_title);
	if (!game_library->window)
		game_error(game_library, " ERROR - Window failed to build\n", 2);
}

static inline char
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
