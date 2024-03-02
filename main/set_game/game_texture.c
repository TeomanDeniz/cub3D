/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 03:32:37 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/20 03:32:39 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../minilibx/mlx.h" /*
#   void *mlx_png_file_to_image(mlx_ptr_t *, char *, int *, int *);
*/
#include "../so_long.h" /*
# define TILE_WIDTH ?
# define TILE_HEIGHT ?
#typedef t_game;
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	*game_texture(t_game game_library, char *file)
{
	void	*result;

	result = mlx_xpm_file_to_image(game_library->mlx, file, \
		&(int){0}, &(int){0});
	return (result);
}
