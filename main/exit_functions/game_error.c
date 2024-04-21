/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_error.c                                       :+:      :+:    :+:   */
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
# define EXIT_FAILURE 1
#   void exit(int);
#        */
#include "../../minilibx/mlx.h" /*
#    int mlx_destroy_window(void *, void *);
#        */
#include "../../libft/libft.h" /*
#    int ft_strlen(char *);
#        */
#include <unistd.h> /*
#sszie_t write(int, void *, size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	game_error(t_game game, char *message)
{
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_FAILURE);
}
