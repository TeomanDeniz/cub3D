/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 01:44:22 by hdeniz            #+#    #+#             */
/*   Updated: 2024/03/08 01:44:25 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../cub3D.h" /*
#typedef *t_game;
#   void free_game(t_game);
#*/
#include <stdlib.h> /*
#   void exit(int);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	exit_game(t_game game, int error_level)
{
	free_game(game);
	exit(error_level);
}
