/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 07:26:06 by hdeniz            #+#    #+#             */
/*   Updated: 2024/03/08 07:26:07 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../cub3D.h" /*
# define SHADOW_DISTANCE
# define WINDOW_HEIGHT
# define WALL_SIZE
#typedef t_game;
#   void putpixel(t_game, int, int, uint);
#        */
#include "../../libft/ft_math/ft_math.h" /*
#  float ft_fminf(float, float);
#  float ft_fabsf(float);
#    int ft_imax(int, int);
#    int ft_iabs(int);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	shadow_pixel(register int fade, register int color);
extern __inline__ int	find_pixel(t_game game, register int index);
extern __inline__ void	draw_left_to_right(t_game game, t_render render);
extern __inline__ void	draw_up_to_down(t_game game, t_render render);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	render(t_game game)
{
	t_render		render;

	render.index = -1;
	render.z = game->skyline - WINDOW_HEIGHT / 2;
	render.middle_to_up = -1 + ((render.z - (game->window_height_center)) * \
		(render.z >= (game->window_height_center)));
	render.middle_to_down = ft_iabs(((render.z + (game->window_height_center)) \
		* (render.z <= -(game->window_height_center))));
	while (++render.index, render.index < game->number_of_rays)
	{
		if (game->ray[render.index].distance == 0.0F)
			break ;
		draw_left_to_right(game, render);
	}
}

extern __inline__ void
	draw_left_to_right(t_game game, t_render render)
{
	render.fade_color = game->ray[render.index].distance * SHADOW_DISTANCE;
	render.wall_height = (int)ft_fminf(WALL_SIZE + \
		ft_fabsf(render.z), WALL_SIZE / game->ray[render.index].distance);
	render.check_up = render.wall_height - ((render.z - \
		game->window_height_center) * \
		(render.z <= -game->window_height_center));
	render.check_down = render.wall_height - \
		((render.z + game->window_height_center) * \
		render.z >= game->window_height_center);
	render.ray_width = (int)(((float)render.index) * game->wall_pixel_width);
	render.x = -1;
	while (++render.x, render.x < game->wall_pixel_width)
		draw_up_to_down(game, render);
}

extern __inline__ void
	draw_up_to_down(t_game game, t_render render)
{
	register int	y;

	y = render.middle_to_up;
	while (++y, y < render.check_up && !(y - render.z > WINDOW_HEIGHT))
		putpixel(game, render.ray_width + render.x, game->skyline - y, \
			shadow_pixel(render.fade_color, find_pixel(game, render.index)));
	y = render.middle_to_down;
	y = ft_iabs(y);
	while (++y, y < render.check_down && !(game->skyline - y > WINDOW_HEIGHT))
		putpixel(game, render.ray_width + render.x, game->skyline + y, \
			shadow_pixel(render.fade_color, find_pixel(game, render.index)));
}

extern __inline__ int
	find_pixel(t_game game, register int index)
{
	(void)game;
	(void)index;
	return (0XFFFFFF);
}

extern __inline__ int
	shadow_pixel(register int fade, register int color)
{
	int	result;

	if (SHADOW_ON)
	{
		result = ft_imax(color - \
			((fade << 8) + (fade << 16) + fade) \
			, 0);
		return (result);
	}
	result = color;
	return (result);
}
