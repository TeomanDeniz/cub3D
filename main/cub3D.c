/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:40:55 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/05 14:40:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../minilibx/mlx.h" /*
#    int mlx_loop(void *);
#    int mlx_clear_window(void *, void *);
#   void *mlx_new_window(void *, int, int, char const *);
#   void *mlx_new_image(void *, int, int);
#   char *mlx_get_data_addr(void *, int *, int *, int *);
#    int mlx_hook(void *, int, int, int (*f)(), void *);
#    int mlx_destroy_window(void *, void *);
*/
#include "so_long.h" /*
# struct s_game;
#   void set_game(struct s_game *, char **);
#   void check_map(char *, struct s_game *);
#    int close_window(struct s_game *);
#    int key_down(int, struct s_game *);
#    int key_up(int, struct s_game *);
#   void game_error(t_game, char *, char);
#   void map_generator(t_game);
#   void game(t_game);
#   void player_position(t_game);
#   void draw_background(t_game);
#   void draw_wall(t_game);
#   void draw_item(t_game);
#   void draw_gate(t_game);
#   void draw_player(t_game);
#   void debug(t_game);
#typedef t_game;
*/
#include <stdlib.h> /*
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
#   void free(void *);
#   void exit(int);
*/
#include "../libft/libft.h" /*
#    int ft_strlen(const char *const);
*/
#include <unistd.h> /*
#ssize_t write(int, const void *, size_t);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static inline int	loop(t_game game);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	main(int argc, char **argv)
{
	struct s_game	game;

	game = (struct s_game){0};
	if (argc < 2)
		if (!game.map)
			return (EXIT_FAILURE);
	if (!game.map)
		check_map(argv[1], &game);
	set_game(&game, argv);
	mlx_loop_hook(game.mlx, loop, &game);
	mlx_hook(game.window, 17, (1L << 0), close_window, &game);
	mlx_hook(game.window, 2, 1L << 0, key_down, &game);
	mlx_hook(game.window, 3, 1L << 1, key_up, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}

static inline int
	loop(t_game game)
{
	if (((game->fps) % (game->game_speed)) == 0)
	{
		game(game);
		player_position(game);
		draw_background(game);
		draw_wall(game);
		debug(game);
	}
	if (game->fps >= 0X100000)
		game->fps = 1;
	game->fps++;
	return (0);
}
