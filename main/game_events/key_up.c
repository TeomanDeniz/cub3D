/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 04:22:34 by hdeniz            #+#    #+#             */
/*   Updated: 2024/03/08 04:22:35 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../cub3D.h" /*
# define LETTER_KEY_LEFT
# define LETTER_KEY_RIGHT
# define LETTER_KEY_UP
# define LETTER_KEY_DOWN
# define ARROW_KEY_LEFT
# define ARROW_KEY_RIGHT
# define ARROW_KEY_UP
# define ARROW_KEY_DOWN
#typedef *t_game;
*/
#include <stdbool.h> /*
#define false;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	key_up(int key, void *arg)
{
	t_game	game;

	game = (t_game)arg;
	if (key == LETTER_KEY_DOWN)
		game->move[0] = false;
	if (key == LETTER_KEY_UP)
		game->move[1] = false;
	if (key == LETTER_KEY_LEFT)
		game->move[2] = false;
	if (key == LETTER_KEY_RIGHT)
		game->move[3] = false;
	if (key == ARROW_KEY_DOWN)
		game->move[4] = false;
	if (key == ARROW_KEY_UP)
		game->move[5] = false;
	if (key == ARROW_KEY_LEFT)
		game->move[6] = false;
	if (key == ARROW_KEY_RIGHT)
		game->move[7] = false;
	return (0);
}
