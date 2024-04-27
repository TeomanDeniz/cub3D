/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 02:47:42 by hdeniz            #+#    #+#             */
/*   Updated: 2024/03/08 02:47:43 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../cub3D.h" /*
# define M_2XPI
# define RENDER_EPSILON
#typedef *t_game;
#   void error_game(t_game, char *);
#*/
#include <stdlib.h> /*
#typedef size_t;
#*/
#include "../../libft/ft_math/ft_math.h" /*
# define M_PI
# double ft_sin(double);
# double ft_cos(double);
# double ft_fmod(double, double);
#*/
#include "../../libft/libft.h" /*
# size_t ft_strlen(char *);
# size_t ft_matrixrlen(char **);
#*/
#include <math.h>
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	calculate(t_game game, register int index);
/* *************************** [^] PROTOTYPES [^] *************************** */

void draw_column(t_game game, int column, double distance_to_wall);
double cast_ray(t_game game, double ray_cos, double ray_sin);


void
	raycasting(t_game game)
{
	register size_t	index;

	index = 0;
	while (index < game->photon_len)
	{
		game->photon[index].distance = 0.0;
		calculate(game, index);
		game->photon[index].distance *= cos(game->photon[index].angle);
		++index;
	}
}

extern __inline__ void
	calculate(t_game game, register int index)
{
	register double	x;
	register double	y;
	register double	ray_angle;

	while (1)
	{
		ray_angle = game->rotate_angle - game->photon[index].angle;
		x = game->photon[index].distance * sin(ray_angle) + game->player_x;
		y = game->photon[index].distance * cos(ray_angle) + game->player_y;

		if (x < 0.0)
			x = 0.0;
		if (y < 0.0)
			y = 0.0;
		if (x >= ft_strlen(*game->map))
			x = ft_strlen(*game->map) - 1.0;
		if (y >= ft_matrixrlen(game->map))
			y = ft_matrixrlen(game->map) - 1.0;
		if (game->map[(long)y][(long)x] == '1' || (
			game->map[(long)(y - 0.01)][(long)x] == '1' &&
			game->map[(long)(y + 0.01)][(long)(x + 0.01)] == '1') || (
			game->map[(long)(y + 0.01)][(long)x] == '1' &&
			game->map[(long)(y - 0.01)][(long)(x + 0.01)] == '1') \
			)
			return ;
		game->photon[index].distance += RENDER_EPSILON;
		putpixel(game, x * 40, y * 40, 0X6666FF);
	}
}
