/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:40:55 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/05 14:40:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../minilibx/mlx.h" /*
#    int mlx_loop(void *);
#    int mlx_loop_hook(void *, int (*f)(), void *);
#    int mlx_hook(void *, int, int, int (*f)(), void *);
#    int mlx_put_image_to_window(void *, void *, void *, int, int);
#*/
#include "cub3D.h" /*
# struct s_game;
#typedef t_game;
#   void raycasting(t_game);
#   void setup(game_t);
#    int close_game(void *);
#    int key_down(int, void *);
#    int key_up(int, void *);
#   void render(t_game);
#   void raycasting(t_game);
#   void clear_window(t_game);
#*/
#include <stdlib.h> /*
# define EXIT_SUCCESS
#*/
#include "../libft/ft_math/ft_math.h" /*
# define M_PI
# double ft_lerp(double, double, double);
#*/

#include <unistd.h>

/* **************************** [^] INCLUDES [^] **************************** */

int
	loop(void *arg)
{
	t_game	game;

	game = (t_game)arg;
	clear_window(game);
	if (game->setup)
		render(game);
	else
		game->setup = true;
	raycasting(game);
	if (game->setup)
		mlx_put_image_to_window(game->mlx, game->window, \
			game->render.image, 0, 0);
	return (0);
}

int
	main(void)
{
	struct s_game	game;

	game.map = (char *[100])\
	{\
		(char [16]){"111101111"}, \
		(char [16]){"100000001"}, \
		(char [16]){"100100001"}, \
		(char [16]){"101000001"}, \
		(char [16]){"100000001"}, \
		(char [16]){"100000001"}, \
		(char [16]){"111111111"}, \
		NULL
	};
	setup(&game);

	mlx_hook(game.window, 17, (1L << 0), close_game, (void *)&game);
	mlx_hook(game.window, 2, 1L << 0, key_down, (void *)&game);
	mlx_hook(game.window, 3, 1L << 1, key_up, (void *)&game);
	mlx_loop_hook(game.mlx, loop, (void *)&game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
