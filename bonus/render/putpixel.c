/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpixel.c                                         :+:      :+:    :+:   */
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
/* **************************** [^] INCLUDES [^] **************************** */

void
	putpixel(t_game game, register int x, register int y, register int color)
{
	if (x < 0 || y < 0 || \
		(unsigned)x >= game->canvas.x || (unsigned)y >= game->canvas.y)
		return ;
	*(unsigned int *)&game->canvas.buffer \
		[y * game->canvas.line_length + (x << 2)] = (unsigned int)color;
}
