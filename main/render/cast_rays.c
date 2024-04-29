/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:40:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/04/20 14:40:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../cub3D.h" /*
#typedef t_game;
#        */
#include "../../libft/ft_math/ft_math.h" /*
#  float ft_cosf(float);
#  float ft_sinf(float);
#        */
#include "../../libft/libft.h" /*
# size_t ft_strlen(char *);
# size_t ft_matrixrlen(char **);
#        */
#include <stdlib.h> /*
#typedef size_t;
#        */

#include <math.h>
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
extern __inline__ void	ray_going(t_game game, register size_t index);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	cast_rays(t_game game)
{
	register size_t 	index;

	index = 0;
	while (index < game->number_of_rays)
	{
		game->ray[index].distance = 0.0;
		ray_going(game, index);
		game->ray[index].distance *= ft_cosf(game->ray[index].theta);
		++index;
	}
}

extern __inline__ void
	ray_going(t_game game, register size_t index)
{
	register float	x;
	register float	y;
	register float	ray_angle;

	while (1)
	{
		ray_angle = game->theta_rotation - game->ray[index].theta;
		x = game->ray[index].distance * sinf(ray_angle) + game->x;
		y = game->ray[index].distance * cosf(ray_angle) + game->y;
		if (x < 0.0F)
			x = 0.0F;
		if (y < 0.0F)
			y = 0.0F;
		if (x >= (float)ft_strlen(*game->map))
			x = (float)ft_strlen(*game->map) - 1.0F;
		if (y >= (float)ft_matrixrlen(game->map))
			y = (float)ft_matrixrlen(game->map) - 1.0F;
		if (game->map[(int)y][(int)x] == '1' || \
			game->map[(int)(y + 0.01F)][(int)x] == '1')
			return ;
		game->ray[index].distance += RENDER_EPSILON;
		putpixel(game, x * 10, y * 10, 0X6666FF);
	}
}
