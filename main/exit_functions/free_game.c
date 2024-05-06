/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
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
#include <stdlib.h> /*
#   void free(void *);
#        */
#include "../../minilibx/mlx.h" /*
#    int mlx_destroy_window(void *, void *);
#    int mlx_destroy_image(void *, void *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	free_game(t_game game)
{
	if (!!game->ray)
		free(game->ray);
	if (!!game->mlx && !!game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (!!game->canvas.image)
		mlx_destroy_image(game->mlx, game->canvas.image);
}
