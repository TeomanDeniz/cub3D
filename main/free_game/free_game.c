/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 01:45:28 by hdeniz            #+#    #+#             */
/*   Updated: 2024/03/08 01:45:28 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../minilibx/mlx.h" /*
#    int mlx_destroy_window(void *, void *);
#*/
#include "../cub3D.h" /*
#typedef *t_game;
#   void free_game(t_game);
#   void exit_game(t_game, int);
#*/
#include "../../libft/libft.h" /*
#   bool ft_free_matrix(char ***);
#   bool ft_safe_free(void **);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	free_game(t_game game)
{
	//if (!!game->map)
	//	ft_free_matrix(&game->map);
	if (!!game->render.image)
		mlx_destroy_image(game->mlx, game->render.image);
	if (!!game->photon)
		ft_safe_free((void **)&game->photon);
	if (!!game->mlx && !!game->window)
		mlx_destroy_window(game->mlx, game->window);
}
