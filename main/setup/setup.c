/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:40:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/04/20 14:40:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../minilibx/mlx.h" /*
#   void *mlx_init(void);
#   void *mlx_new_window(void *, int, int, char *);
#   void *mlx_new_image(void *, int, int);
#   char *mlx_get_data_addr(void *, int *, int *, int *);
#    int mlx_mouse_move(void *, void *, int, int);
#    int mlx_mouse_hide(void *, void *);
#        */
#include "../../libft/libft.h" /*
#    int ft_strlen(char *);
#    int ft_matrixlen(char **);
#        */
#include "../cub3D.h" /*
# define WINDOW_WIDTH
# define WINDOW_HEIGHT
# define PERSPECTIVE
# define RAY_MULTIPY
#typedef t_game;
#   void game_error(t_game, char *);
#    int map_control(t_game, char *, t_map *);
#        */
#include <stdlib.h> /*
#   void *malloc(size_t);
#        */
#include "../../libft/ft_math/ft_math.h" /*
# define M_PI_F
#  float ft_fmodf(float, float);
#  float ft_cosf(float);
#  float ft_sinf(float);
#  float ft_floorf(float);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ char	*get_title(char **argv);
extern __inline__ void	set_key_inputs(t_game game);
extern __inline__ void	set_rays(t_game game);
extern __inline__ void	setup2(t_game game);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	setup(t_game game)
{
	game->map = NULL;
	game->ray = NULL;
	game->window = NULL;
	game->canvas.image = NULL;
	game->textures_are_ready = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		game_error(game, "MLX failed to create.");
	if (game->argc != 2)
		game_error(game, "Give at least one cub file to game!");
	if (map_control(game, *(game->argv + 1)) == -1)
		game_error(game, NULL);
	game->textures_are_ready = 1;
	game->canvas.image = NULL;
	game->window_title = get_title(game->argv);
	game->window = mlx_new_window(\
		game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, \
		game->window_title);
	if (!game->window)
		game_error(game, "MLX_WINDOW failed to open.");
	set_key_inputs(game);
	game->perspective = PERSPECTIVE;
	game->theta_perspective = ft_fmodf((game->perspective / 2.0F) * \
		(M_PI_F / 180.0F) + 0.0001F, 2.0F * M_PI_F);
	setup2(game);
}

extern __inline__ void
	setup2(t_game game)
{
	game->number_of_rays = (int)(game->perspective * RAY_MULTIPY);
	game->wall_pixel_width = (float)WINDOW_WIDTH / (float)game->number_of_rays;
	game->target_x = game->x;
	game->target_y = game->y;
	game->map_width = ft_strlen(*game->map);
	game->map_height = ft_matrixlen((const char **)game->map);
	game->skyline = (float)(WINDOW_HEIGHT / 2);
	game->target_skyline = game->skyline;
	game->cos_theta_rotation = ft_cosf(game->theta_rotation);
	game->sin_theta_rotation = ft_sinf(game->theta_rotation);
	game->window_height_center = WINDOW_HEIGHT / 2;
	set_rays(game);
	game->canvas.image = \
		mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->canvas.image)
		game_error(game, ERROR4);
	game->canvas.buffer = mlx_get_data_addr(game->canvas.image, \
		&game->canvas.bits_per_pixel, &game->canvas.line_length, \
		&game->canvas.endian);
	game->canvas.x = WINDOW_WIDTH;
	game->canvas.y = WINDOW_HEIGHT;
	mlx_mouse_move(game->mlx, game->window, \
		WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	mlx_mouse_hide(game->mlx, game->window);
}

extern __inline__ void
	set_rays(t_game game)
{
	register int	index;

	game->ray = (struct s_ray *) malloc(sizeof(struct s_ray) * RAY_MULTIPY * \
		game->perspective);
	if (!game->ray)
		game_error(game, "game->ray failed to allocate.");
	index = 0;
	while (index < game->number_of_rays)
	{
		game->ray[index].hit = 0;
		game->ray[index].distance = 0.0F;
		game->ray[index].theta = ((index / \
			(ft_floorf(game->perspective * RAY_MULTIPY) / 2.0F)) * \
			game->theta_perspective) - game->theta_perspective;
		game->ray[index].sin_theta = ft_sinf(M_PI_2_F - game->ray[index].theta);
		++index;
	}
}

extern __inline__ void
	set_key_inputs(t_game game)
{
	game->key.w = 0U;
	game->key.a = 0U;
	game->key.d = 0U;
	game->key.s = 0U;
	game->key.arrow_l = 0U;
	game->key.arrow_r = 0U;
	game->key.arrow_u = 0U;
	game->key.arrow_d = 0U;
}

extern __inline__ char
	*get_title(char **argv)
{
	register int	eax;

	if (!argv[1])
		return ("[Unknown Map]");
	eax = ft_strlen(argv[1]) - 1;
	while ((eax > 0) && (argv[1][eax] != '/') && (argv[1][eax] != '\\'))
		--eax;
	return (argv[1] + eax + (eax != 0));
}
