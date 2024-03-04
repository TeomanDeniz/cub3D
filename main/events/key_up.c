/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:03:22 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/14 17:03:23 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../so_long.h" /*
# define LETTER_KEY_LEFT 0
# define LETTER_KEY_RIGHT 2
# define LETTER_KEY_UP 13
# define LETTER_KEY_DOWN 1
# define ARROW_KEY_LEFT 123
# define ARROW_KEY_RIGHT 124
# define ARROW_KEY_UP 126
# define ARROW_KEY_DOWN 125
#typedef t_game;
*/
/* **************************** [^] INCLUDES [^] **************************** */

int
	key_up(int key, t_game game)
{
	if (key == LETTER_KEY_DOWN || key == ARROW_KEY_DOWN)
		game->object.player.movement[0] = 0;
	if (key == LETTER_KEY_UP || key == ARROW_KEY_UP)
		game->object.player.movement[1] = 0;
	if (key == LETTER_KEY_LEFT || key == ARROW_KEY_LEFT)
		game->object.player.movement[2] = 0;
	if (key == LETTER_KEY_RIGHT || key == ARROW_KEY_RIGHT)
		game->object.player.movement[3] = 0;
	return (0);
}
