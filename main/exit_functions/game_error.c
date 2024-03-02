/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:21:00 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/08 17:21:02 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../libft/libft.h" /*
#    int ft_strlen(const char *const);
*/
#include "../cub3D.h" /*
#typedef t_game;
*/
#include <stdlib.h> /*
# define EXIT_FAILURE 1
#   void free(void *);
#   void exit(int);
*/
#include <unistd.h> /*
#ssize_t write(int, const void *, size_t);
*/
#include "../../minilibx/mlx.h" /*
#    int mlx_destroy_window(void *, void *);
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	game_error(t_game game, char *error_message, char mode)
{
	write(1, error_message, ft_strlen(error_message));
	if (mode == 2)
	{
		free(game->mlx->font->buffer);
		free(game->mlx->font);
		free(game->mlx);
	}
	if (mode >= 3)
		mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_FAILURE);
}
