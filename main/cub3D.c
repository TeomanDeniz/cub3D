/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:40:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/04/20 14:40:56 by hdeniz           ###   ########.fr       */
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
#        */
#include "cub3D.h" /*
# struct s_game;
#typedef t_game;
#    int key_down(int, t_game);
#    int key_up(int, t_game);
#    int close_game(t_game);
#   void skybox(t_game, int, int);
#   void setup(t_game, int, char **);
#   void cast_rays(t_game);
#        */
#include <stdlib.h> /*
# define EXIT_SUCCESS
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	loop(void *arg)
{
	t_game		game;

	game = (t_game)arg;
	skybox(game, 0X222222, 0X666666);
	render(game);
	cast_rays(game);
	mlx_put_image_to_window(game->mlx, game->window, game->canvas.image, 0, 0);
	return (0);
}

int
	main(int argc, char **argv)
{
	struct s_game	game;

	game.map = (char *[100])\
	{\
		(char [100]){"111111111"}, \
		(char [100]){"100000001"}, \
		(char [100]){"100100001"}, \
		(char [100]){"101000001"}, \
		(char [100]){"100100001"}, \
		(char [100]){"100000001"}, \
		(char [100]){"111111111"}, \
		NULL
	};
	setup(&game, argc, argv);
	mlx_hook(game.window, 17, (1L << 0), close_window, (void *)&game);
	mlx_hook(game.window, 2, 1L << 0, key_down, (void *)&game);
	mlx_hook(game.window, 3, 1L << 1, key_up, (void *)&game);
	mlx_loop_hook(game.mlx, loop, (void *)&game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
