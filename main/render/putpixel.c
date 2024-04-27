/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 07:24:43 by hdeniz            #+#    #+#             */
/*   Updated: 2024/03/08 07:24:44 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../cub3D.h" /*
#typedef *t_game;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	putpixel(t_game game, register int x, register int y, register int color)
{
	char	*pixel;

	if (x >= 0 && x < game->window_x && y >= 0 && y < game->window_y)
	{
		pixel = game->render.buffer + (y * game->render.line_length + x * \
			game->render.bits_per_pixel);
		*(unsigned int *)pixel = color;
	}
}
