/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 01:08:03 by hdeniz            #+#    #+#             */
/*   Updated: 2024/03/08 01:08:04 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../minilibx/mlx.h" /*
#   void *mlx_init(void);
#   void *mlx_new_window(void *, int, int, char const *);

#   void *mlx_new_image(void *, int, int);
#   char *mlx_get_data_addr(void *, int *, int *, int *);
#    int mlx_hook(void *, int, int, int (*f)(), void *);
#    int mlx_destroy_window(void *, void *);
#*/
#include "../cub3D.h" /*
# define ERROR1
# define ERROR2
# define ERROR3
# define DEFULT_WINDOW_X_SIZE
# define DEFULT_WINDOW_Y_SIZE
# define DEFAULT_PERSPECTIVE
# define PHOTON_MULTIPY
# struct s_photon;
#typedef *t_game;
#   void error_game(t_game, char *);
#*/
#include <stdlib.h> /*
#typedef size_t;
#   void *malloc(size_t);
#*/
#include "../../libft/ft_math/ft_math.h" /*
# define M_PI
# double ft_floor(double);
# double ft_fmod(double, double);
#*/
#include <math.h>
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
static void	set_photons(t_game game);
static void	prepare_render(t_game game);
static void	setup2(t_game game);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	setup(t_game game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_game(game, ERROR1);
	game->window = mlx_new_window(game->mlx, DEFULT_WINDOW_X_SIZE, \
		DEFULT_WINDOW_Y_SIZE, "Title");
	if (!game->window)
		error_game(game, ERROR2);
	game->window_x = DEFULT_WINDOW_X_SIZE;
	game->window_y = DEFULT_WINDOW_Y_SIZE;
	game->perspective = DEFAULT_PERSPECTIVE;
	game->photon_len = (size_t)(game->perspective * PHOTON_MULTIPY);
	game->rotate = 180.0; // BURASI DEĞİŞECEK ( + 90.0 olacak)
	game->target_rotate = game->rotate;
	game->player_x = 4.5; // BURASI DEĞİŞECEK
	game->player_y = 0.0; // BURASI DEĞİŞECEK
	game->target_player_x = game->player_x;
	game->target_player_y = game->player_y;
	game->perspective_angle = ft_fmod((game->perspective / 2.0) * \
		(M_PI / 180.0) + 0.0001, 2.0 * M_PI);
	game->rotate_angle = game->rotate * (M_PI / 180.0) + 0.0001;
	game->cos_angle = cos(game->rotate_angle);
	game->sin_angle = sin(game->rotate_angle);
	game->wall_pixel_size = ((double)game->window_x / (double)game->photon_len);
	game->skyline = (double)(game->window_y / 2);
	game->target_skyline = game->skyline;
	setup2(game);
}

static void
	setup2(t_game game)
{
	game->setup = false;
	set_photons(game);
	prepare_render(game);
	game->fix_fish_eye = ((0 / \
		((ft_floor(game->perspective * PHOTON_MULTIPY) / 2)) * \
		game->perspective_angle) - game->perspective_angle) + (\
		((game->photon_len / 2) / ((ft_floor(game->perspective * \
		PHOTON_MULTIPY) / 2)) * game->perspective_angle) - \
		game->perspective_angle);
	game->move[0] = false;
	game->move[1] = false;
	game->move[2] = false;
	game->move[3] = false;
	game->move[4] = false;
	game->move[5] = false;
	game->move[6] = false;
	game->move[7] = false;
	//set_map(game); // SETUP MAP
}

static void
	prepare_render(t_game game)
{
	game->render.image = \
		mlx_new_image(game->mlx, game->window_x, game->window_y);
	if (!game->render.image)
		error_game(game, ERROR4);
	game->render.buffer = mlx_get_data_addr(game->render.image, \
		&game->render.bits_per_pixel, &game->render.line_length, \
		&game->render.endian);
	game->render.bits_per_pixel /= 8;
}

static void
	set_photons(t_game game)
{
	register size_t	index;

	game->photon = (struct s_photon *)malloc(sizeof(struct s_photon) * \
		game->photon_len);
	if (!game->photon)
		error_game(game, ERROR3);
	index = 0;
	while (index < game->photon_len)
	{
		game->photon[index].angle = ((index / \
			(ft_floor(game->perspective * PHOTON_MULTIPY) / 2)) * \
			game->perspective_angle) - game->perspective_angle;
		game->photon[index].fish_eye_fix = 0.7;
		++index;
	}
}
