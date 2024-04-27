/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_down.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 04:22:27 by hdeniz            #+#    #+#             */
/*   Updated: 2024/03/08 04:22:28 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../cub3D.h" /*
# define KEY_ESC
# define LETTER_KEY_LEFT
# define LETTER_KEY_RIGHT
# define LETTER_KEY_UP
# define LETTER_KEY_DOWN
# define ARROW_KEY_LEFT
# define ARROW_KEY_RIGHT
# define ARROW_KEY_UP
# define ARROW_KEY_DOWN
#   void exit_game(t_game, int);
#typedef *t_game;
*/
#include <stdbool.h> /*
#define true;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	key_down(int key, void *arg)
{
	t_game	game;

	game = (t_game)arg;
	if (key == KEY_ESC)
		exit_game(game, 0);
	if (key == LETTER_KEY_DOWN)
		game->move[0] = true;
	if (key == LETTER_KEY_UP)
		game->move[1] = true;
	if (key == LETTER_KEY_LEFT)
		game->move[2] = true;
	if (key == LETTER_KEY_RIGHT)
		game->move[3] = true;
	if (key == ARROW_KEY_DOWN)
		game->move[4] = true;
	if (key == ARROW_KEY_UP)
		game->move[5] = true;
	if (key == ARROW_KEY_LEFT)
		game->move[6] = true;
	if (key == ARROW_KEY_RIGHT)
		game->move[7] = true;
	return (0);
}
