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
#    int close_window(t_game);
#        */
#include <stdlib.h> /*
# define EXIT_SUCCESS
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
extern inline int	loop(t_game game);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	main(int argc, char **argv)
{
	struct s_game	game;

	game.map = (char *[100]){\
		"1111111111", \
		"1000000001", \
		"1000110001", \
		"1000000001", \
		"1000000001", \
		"1000000001", \
		"1000000001", \
		"1111111111", \
	};
	(void)argc, (void)argv;
	game = (struct s_game){0};
	set_game(&game, argv);
	mlx_loop_hook(game.mlx, loop, &game);
	mlx_hook(game.window, 17, (1L << 0), close_window, &game);
	mlx_hook(game.window, 2, 1L << 0, key_down, &game);
	mlx_hook(game.window, 3, 1L << 1, key_up, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}

#include <stdio.h>

extern inline int
	loop(t_game game)
{
	(void)game;
	//calculate_photons(game);
	mlx_put_image_to_window(game->mlx, game->window, game->canvas.image, 0, 0);
	return (0);
}
