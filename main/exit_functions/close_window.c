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
*/
#include "../cub3D.h" /*
#typedef t_game;
*/
#include <stdlib.h> /*
# define EXIT_SUCCESS
#   void exit(int);
*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	close_window(t_game game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
}
