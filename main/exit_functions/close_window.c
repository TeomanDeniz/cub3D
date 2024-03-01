/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:21:23 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/08 17:21:24 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../minilibx/mlx.h" /*
#    int mlx_destroy_window(void *, void *);
#    int mlx_destroy_image(mlx_ptr_t *, mlx_img_list_t *)
*/
#include "../so_long.h" /*
#typedef t_game;
#   void free_objects(t_game);
#   void free_textures(t_game, int);
*/
#include "../../libft/libft.h" /*
#   void ft_free_matrix(char **);
*/
#include <stdlib.h> /*
# define EXIT_SUCCESS 0
#   void exit(int);
*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	close_window(t_game game)
{
	free_textures(game, 0);
	mlx_destroy_window(game->mlx, game->window);
	if (game->map)
		ft_free_matrix(game->map);
	free_objects(game);
	exit(EXIT_SUCCESS);
}
