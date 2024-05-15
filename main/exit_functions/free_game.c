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
#typedef t_image;
#typedef t_game;
#        */
#include <stdlib.h> /*
#   void free(void *);
#        */
#include "../../minilibx/mlx.h" /*
#    int mlx_destroy_window(void *, void *);
#    int mlx_destroy_image(void *, void *);
#        */
#include "../../libft/libft.h" /*
#    int ft_free_matrix(char ***);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	free_game(t_game game)
{
	register int	index;

	if (!!game->ray)
		free(game->ray);
	if (!!game->mlx && !!game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (!!game->canvas.image)
		mlx_destroy_image(game->mlx, game->canvas.image);
	if (game->map != NULL)
		ft_free_matrix(&game->map);
	index = -1;
	while (++index, game->textures_are_ready && \
		index < (int)(sizeof(game->textures) / sizeof(t_image)) && \
		!!game->textures[index].image)
		mlx_destroy_image(game->mlx, game->textures[index].image);
}
