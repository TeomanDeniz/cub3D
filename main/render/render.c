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
extern __inline__ unsigned int	find_pixel(t_game game, t_render render, \
register int textrue_y);
extern __inline__ void			render_set_ray(t_game game, t_render *render);
extern __inline__ void			render_set_ray(t_game game, t_render *render);
extern __inline__ void			render_set_ray_2(t_game game, t_render *render);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	render(t_game game)
{
	t_render	render;

	render.index = -1;
	while (++render.index, render.index < game->number_of_rays)
	{
		render_set_ray(game, &render);
		render.padding = (int)(((float)render.index) * game->wall_pixel_width);
		render.x = -1;
		while (++render.x, render.x < game->wall_pixel_width)
		{
			render.x_coordinates = render.padding + render.x;
			render.y = render.wall_y_start_point;
			render.textrue_y = render.update_textrue_y * render.texture_y_step;
			while ((int)(((float)render.y) <= render.wall_y_end_point))
			{
				putpixel(game, render.x_coordinates, render.y, \
					find_pixel(game, render, render.textrue_y));
				render.textrue_y += render.texture_y_step;
				render.y++;
			}
		}
	}
}

extern __inline__ void
	render_set_ray(t_game game, t_render *render)
{
	if (game->ray[render->index].hit == 0)
		render->textrue_x = -1;
	if (game->ray[render->index].hit == 2)
		render->textrue_x = game->textures[0].x - \
			(int)((float)game->textures[0].x * \
			ft_fmodf(game->ray[render->index].x, 1.0F)) - 1;
	if (game->ray[render->index].hit == 4)
		render->textrue_x = (int)((float)game->textures[0].x * \
			ft_fmodf(game->ray[render->index].x, 1.0F));
	if (game->ray[render->index].hit == 1)
		render->textrue_x = (int)((float)game->textures[0].x * \
			ft_fmodf(game->ray[render->index].y, 1.0F));
	if (game->ray[render->index].hit == 3)
		render->textrue_x = game->textures[0].x - \
			(int)((float)game->textures[0].x * \
			ft_fmodf(game->ray[render->index].y, 1.0F)) - 1;
	render->texture_y_step = (float)game->textures[0].y / \
		((float)WALL_SIZE * 2.0F / game->ray[render->index].distance);
	render->shadow = (int)(game->ray[render->index].distance * SHADOW_DISTANCE);
	render_set_ray_2(game, render);
}

extern __inline__ void
	render_set_ray_2(t_game game, t_render *render)
{
	render->half_wall_size = ft_fminf(WALL_SIZE + \
		ft_fabsf(game->skyline - WINDOW_HEIGHT / 2), WALL_SIZE / \
		game->ray[render->index].distance) * \
		(game->ray[render->index].distance != 0.0);
	render->wall_y_end_point = game->skyline + render->half_wall_size - 1.0F;
	render->wall_y_start_point = \
		ft_imax(game->skyline - render->half_wall_size, 0);
	render->wall_height = (WALL_SIZE / game->ray[render->index].distance + \
		game->skyline) - (game->skyline - WALL_SIZE / \
		game->ray[render->index].distance);
	if (render->wall_height >= WINDOW_HEIGHT)
		render->update_textrue_y = \
		((render->wall_height - (float)WINDOW_HEIGHT)) / 2.0F;
	else
		render->update_textrue_y = 0.0F;
}

extern __inline__ unsigned int
	find_pixel(t_game game, t_render render, register int textrue_y)
{
	return (*(unsigned int *)&game->textures[0].buffer[textrue_y * \
		game->textures[0].line_length + (render.textrue_x << 2)]);
}

/*
extern __inline__ unsigned int
	find_pixel(t_game game, t_render render, register int textrue_y)
{
	static int			current_texture_y = -1;
	static unsigned int	current_color = 0;
	unsigned int		result;

	if (current_texture_y == textrue_y)
		return (current_color);
	if (current_texture_y == -1)
	{
		current_texture_y = textrue_y;
		result = *(unsigned int *)&game->textures[0].buffer[textrue_y * \
			game->textures[0].line_length + (render.textrue_x << 2)];
		current_color = \
			(ft_imax(((char *)&result)[2] & 0XFF - render.shadow, 0) << 16) + \
			(ft_imax(((char *)&result)[1] & 0XFF - render.shadow, 0) << 8) + \
			ft_imax(0[((char *)&result)] & 0XFF - render.shadow, 0);
		return (current_color);
	}
	if (render.textrue_x == -1)
		return (0X000000);
	current_texture_y = textrue_y;
	result = *(unsigned int *)&game->textures[0].buffer[textrue_y * \
		game->textures[0].line_length + (render.textrue_x << 2)];
	current_color = \
		(ft_imax(((char *)&result)[2] & 0XFF - render.shadow, 0) << 16) + \
		(ft_imax(((char *)&result)[1] & 0XFF - render.shadow, 0) << 8) + \
		ft_imax(0[((char *)&result)] & 0XFF - render.shadow, 0);
	return (current_color);
}
*/
