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
#    int mlx_put_image_to_window(void *, void *, void *, int, int);
#    int mlx_hook(void *, int, int, int (*f)(), void *);
#    int mlx_loop_hook(void *, int (*f)(), void *);
#    int mlx_loop(void *);
#        */
#include "./cub3D.h" /*
# struct s_game;
#typedef t_game;
#   void input_events(t_game);
#   void skybox(t_game, int, int);
#   void render(t_game);
#   void cast_rays(t_game);
#   void setup(t_game, int, char **);
#    int close_window(t_game);
#    int key_down(int, t_game);
#    int key_up(int, t_game);
#        */
#include <stdlib.h> /*
# define EXIT_SUCCESS
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	loop(void *arg)
{
	t_game	game;

	game = (t_game)arg;
	input_events(game);
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

	game.map = (char *[]) \
	{\
		"111111111", \
		"100000001", \
		"100100001", \
		"101000001", \
		"100100001", \
		"100000000", \
		"000000100", \
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
