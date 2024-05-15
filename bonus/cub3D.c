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
#   void lidar(t_game);
#   void setup(t_game, int, char **);
#    int close_window(t_game);
#    int key_down(int, t_game);
#    int key_up(int, t_game);
#   void minimap(t_game, int, int);
#        */
#include <stdlib.h> /*
# define EXIT_SUCCESS
#        */
#include "../libft/ft_math/ft_math.h" /*
#  float ft_lerpf(float, float, float);
#    int ft_rand(int, int);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	loop(void *arg);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	main(int argc, char **argv)
{
	struct s_game	game;

	game.argv = argv;
	game.argc = argc;
	game.textures[0].image = NULL;
	game.textures[1].image = NULL;
	game.textures[2].image = NULL;
	game.textures[3].image = NULL;
	game.textures[4].image = NULL;
	game.textures[5].image = NULL;
	game.textures[6].image = NULL;
	game.textures[7].image = NULL;
	game.textures[8].image = NULL;
	setup(&game);
	mlx_hook(game.window, 17, (1L << 0), close_window, (void *)&game);
	mlx_hook(game.window, 2, 1L << 0, key_down, (void *)&game);
	mlx_hook(game.window, 3, 1L << 1, key_up, (void *)&game);
	mlx_loop_hook(game.mlx, loop, (void *)&game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}

extern __inline__ int
	loop(void *arg)
{
	t_game	game;

	game = (t_game)arg;
	game->target_shadow = (float)ft_rand(-50, 240);
	input_events(game);
	skybox(game, game->floor_color, game->ceiling_color);
	lidar(game);
	render(game);
	minimap(game, -3, -3);
	mlx_put_image_to_window(game->mlx, game->window, game->canvas.image, 0, 0);
	game->shadow = ft_lerpf(game->shadow, game->target_shadow, 0.02F);
	return (0);
}
