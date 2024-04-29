/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_down.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:40:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/04/20 14:40:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../cub3D.h" /*
# define KEY_ESC 53
# define LETTER_KEY_LEFT 0
# define LETTER_KEY_RIGHT 2
# define LETTER_KEY_UP 13
# define LETTER_KEY_DOWN 1
# define ARROW_KEY_LEFT 123
# define ARROW_KEY_RIGHT 124
# define ARROW_KEY_UP 126
# define ARROW_KEY_DOWN 125
#   void close_window(t_game);
#typedef t_game;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	key_down(int key, t_game game)
{
	if (key == KEY_ESC)
		close_window(game);
	if (key == LETTER_KEY_DOWN)
		game->key[0] = 1;
	if (key == LETTER_KEY_UP)
		game->key[1] = 1;
	if (key == LETTER_KEY_LEFT)
		game->key[2] = 1;
	if (key == LETTER_KEY_RIGHT)
		game->key[3] = 1;
	if (key == ARROW_KEY_DOWN)
		game->key[4] = 1;
	if (key == ARROW_KEY_UP)
		game->key[5] = 1;
	if (key == ARROW_KEY_LEFT)
		game->key[6] = 1;
	if (key == ARROW_KEY_RIGHT)
		game->key[7] = 1;
	return (0);
}
