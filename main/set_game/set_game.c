/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:40:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/04/20 14:40:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../minilibx/mlx.h" /*
#   void *mlx_new_window(void *, int, int, char const *);
#        */
#include "../../libft/libft.h" /*
#    int ft_strlen(char *);
#        */
#include "../cub3D.h" /*
# define WINDOW_WIDTH
# define WINDOW_HEIGHT
# define PERSPECTIVE
# define RAY_MULTIPY
#typedef t_game;
#   void game_error(t_game, char *);
#        */
#include <stdlib.h> /*
#   void *malloc(size_t);
#        */
#include "../../libft/ft_math/ft_math.h" /*
# define M_PI
# double ft_floor(double);
# double ft_fmod(double, double);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern inline char	*get_title(char **argv);
extern inline void	set_key_inputs(t_game game);
extern inline void	set_rays(t_game game);
extern inline void	prepare_canvas(t_game game);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	set_game(t_game game, char **argv)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		game_error(game, "MLX failed to create.");
	game->window_title = get_title(argv);
	game->window = mlx_new_window(\
		game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, \
		game->window_title);
	if (!game->window)
		game_error(game, "MLX_WINDOW failed to open.");
	game->perspective = PERSPECTIVE;
	set_key_inputs(game);
	game->perspective = PERSPECTIVE;
	game->theta_perspective = ft_fmod((game->perspective / 2.0) * \
		(M_PI / 180.0) + 0.0001, 2.0 * M_PI);
	game->ray_size = (size_t)(game->perspective * RAY_MULTIPY);
	game->x = 3.5; // HARİTAYA GÖRE GÜNCELLENECEEK
	game->y = 3.5; // HARİTAYA GÖRE GÜNCELLENECEEK
	game->theta_rotation = 1.57; // HARİTAYA GÖRE GÜNCELLENECEEK
	game->wall_pixel_width = ((double)WINDOW_WIDTH / (double)game->ray_size);
	set_rays(game);
	prepare_canvas(game);
}

extern inline void
	prepare_canvas(t_game game)
{
	game->canvas.image = \
		mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->canvas.image)
		game_error(game, ERROR4);
	game->canvas.buffer = mlx_get_data_addr(game->canvas.image, \
		&game->canvas.bits_per_pixel, &game->canvas.line_length, \
		&game->canvas.endian);
	game->canvas.bits_per_pixel /= 8;
}

extern inline void
	set_rays(t_game game)
{
	register size_t	index;

	game->ray = (struct s_ray *) malloc(sizeof(struct s_ray) * RAY_MULTIPY * \
		game->perspective);
	if (!game->ray)
		game_error(game, "game->ray failed to allocate.");
	index = 0;
	while (index < game->ray_size)
	{
		game->ray[index].view = ((index / \
			(ft_floor(game->perspective * RAY_MULTIPY) / 2)) * \
			game->theta_perspective) - game->theta_perspective;
		++index;
		game->ray[index].theta = 1.57 - game->theta_perspective;
	}
}

extern inline void
	set_key_inputs(t_game game)
{
	game->movement[0] = 0;
	game->movement[1] = 0;
	game->movement[2] = 0;
	game->movement[3] = 0;
	game->movement[4] = 0;
	game->movement[5] = 0;
	game->movement[6] = 0;
	game->movement[7] = 0;
}

extern inline char
	*get_title(char **argv)
{
	register int	eax;

	if (!argv[1])
		return ("[Random Map]"); // BURAYA BAK
	eax = ft_strlen(argv[1]) - 1;
	while ((eax > 0) && (argv[1][eax] != '/') && (argv[1][eax] != '\\'))
		--eax;
	return (argv[1] + eax + (eax != 0));
}
