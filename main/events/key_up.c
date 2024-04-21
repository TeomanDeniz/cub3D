/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:40:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/04/20 14:40:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../cub3D.h" /*
# define LETTER_KEY_LEFT 0
# define LETTER_KEY_RIGHT 2
# define LETTER_KEY_UP 13
# define LETTER_KEY_DOWN 1
# define ARROW_KEY_LEFT 123
# define ARROW_KEY_RIGHT 124
# define ARROW_KEY_UP 126
# define ARROW_KEY_DOWN 125
#typedef t_game;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	key_up(int key, t_game game)
{
	if (key == LETTER_KEY_DOWN)
		game->movement[0] = 0;
	if (key == LETTER_KEY_UP)
		game->movement[1] = 0;
	if (key == LETTER_KEY_LEFT)
		game->movement[2] = 0;
	if (key == LETTER_KEY_RIGHT)
		game->movement[3] = 0;
	if (key == ARROW_KEY_DOWN)
		game->movement[4] = 0;
	if (key == ARROW_KEY_UP)
		game->movement[5] = 0;
	if (key == ARROW_KEY_LEFT)
		game->movement[6] = 0;
	if (key == ARROW_KEY_RIGHT)
		game->movement[7] = 0;
	return (0);
}
