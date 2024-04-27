/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
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
# define EXIT_SUCCESS
#   void exit(int);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	close_game(void *arg)
{
	t_game	game;

	game = (t_game)arg;
	free_game(game);
	exit(EXIT_SUCCESS);
}
