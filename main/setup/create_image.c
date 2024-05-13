/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:40:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/04/20 14:40:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../minilibx/mlx.h" /*
#   char *mlx_get_data_addr(void *, int *, int *, int *);
#   void *mlx_xpm_file_to_image(void *, char *, int *, int *);
#        */
#include "../cub3D.h" /*
#typedef t_game;
#   void game_error(t_game, char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	create_image(t_game game, t_image *image, char *path)
{
	if (!path)
		game_error(game, "create_image.c: <path> is null!");
	image->image = mlx_xpm_file_to_image(game->mlx, path, (signed *)&image->x, \
		(signed *)&image->y);
	if (!image->image)
		game_error(game, "Incorrect Path");
	image->buffer = mlx_get_data_addr(image->image, \
		&image->bits_per_pixel, &image->line_length, \
		&image->endian);
	image->size = image->x * image->y;
}
