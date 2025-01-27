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
#  float ft_fmodf(float, float);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ unsigned int	find_pixel(t_game game, t_render render, \
register int texture_y);
extern __inline__ void			render_set_ray(t_game game, t_render *render);
extern __inline__ void			render_set_ray_2(t_game game, t_render *render);
extern __inline__ unsigned int	shadow_wall(unsigned int color, \
t_render render);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	render(t_game game)
{
	t_render	render;

	render.texture_x = 0;
	render.index = -1;
	while (++render.index, render.index < game->number_of_rays)
	{
		render.hit = game->ray[render.index].hit - 1;
		render_set_ray(game, &render);
		render.padding = (int)(((float)render.index) * game->wall_pixel_width);
		render.x = -1;
		while (++render.x, render.x < game->wall_pixel_width)
		{
			render.x_coordinates = render.padding + render.x;
			render.y = render.wall_y_start_point;
			render.texture_y = render.update_texture_y * render.texture_y_step;
			while ((int)(((float)render.y) <= render.wall_y_end_point))
			{
				putpixel(game, render.x_coordinates, render.y, \
					find_pixel(game, render, render.texture_y));
				render.texture_y += render.texture_y_step;
				render.y++;
			}
		}
	}
}

extern __inline__ void
	render_set_ray(t_game game, t_render *render)
{
	if (render->hit == -1)
		render->texture_x = -1;
	else if (render->hit == 0)
		render->texture_x = (int)((float)game->textures[render->hit].x * \
			ft_fmodf(game->ray[render->index].y, 1.0F));
	else if (render->hit == 1)
		render->texture_x = game->textures[render->hit].x - \
			(int)((float)game->textures[render->hit].x * \
			ft_fmodf(game->ray[render->index].x, 1.0F)) - 1;
	else if (render->hit == 2)
		render->texture_x = game->textures[render->hit].x - \
			(int)((float)game->textures[render->hit].x * \
			ft_fmodf(game->ray[render->index].y, 1.0F)) - 1;
	else if (render->hit == 3)
		render->texture_x = (int)((float)game->textures[render->hit].x * \
			ft_fmodf(game->ray[render->index].x, 1.0F));
	render->texture_y_step = (float)game->textures[render->hit].y / \
		((float)WALL_SIZE * 2.0F / game->ray[render->index].distance);
	render->shadow = (int)(game->ray[render->index].distance * SHADOW_DISTANCE);
	render->shadow_r = render->shadow << 16;
	render->shadow_g = render->shadow << 8;
	render->shadow_b = render->shadow;
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
	if ((int)render->wall_y_end_point > WINDOW_HEIGHT)
		render->wall_y_end_point = (float)WINDOW_HEIGHT;
	render->wall_y_start_point = game->skyline - render->half_wall_size;
	if (render->wall_y_start_point < 0)
		render->wall_y_start_point = 0;
	render->wall_height = (WALL_SIZE / game->ray[render->index].distance + \
		game->skyline) - (game->skyline - WALL_SIZE / \
		game->ray[render->index].distance);
	render->update_texture_y = ((render->wall_height - \
		(float)WINDOW_HEIGHT)) / 2.0F - (int)(game->skyline - WALL_SIZE);
	if (render->update_texture_y < 0)
		render->update_texture_y = 0;
}

extern __inline__ unsigned int
	find_pixel(t_game game, t_render render, register int texture_y)
{
	unsigned int			color;
	register unsigned int	pixel_coordinate;

	pixel_coordinate = texture_y * \
		game->textures[render.hit].line_length + (render.texture_x << 2);
	if (render.texture_x >= 0 && texture_y >= 0 && \
		(unsigned)render.texture_x < game->textures[render.hit].x && \
		render.texture_y < game->textures[render.hit].y)
		color = *(unsigned int *) \
			&game->textures[render.hit].buffer[pixel_coordinate];
	else
		return (0);
	if (!SHADOW_ON)
		return (color);
	return (shadow_wall(color, render));
}

extern __inline__ unsigned int
	shadow_wall(unsigned int color, t_render render)
{
	register int	red;
	register int	green;
	register int	blue;

	red = ((color & 0XFF0000) - render.shadow_r);
	green = ((color & 0X00FF00) - render.shadow_g);
	blue = ((color & 0X0000FF) - render.shadow_b);
	if (red < 0)
		red = 0;
	if (green < 0)
		green = 0;
	if (blue < 0)
		blue = 0;
	color = (red + green + blue);
	return (color);
}
