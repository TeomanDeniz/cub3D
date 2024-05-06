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
	if (key == LETTER_KEY_UP)
		game->key.w = 0U;
	if (key == LETTER_KEY_LEFT)
		game->key.a = 0U;
	if (key == LETTER_KEY_DOWN)
		game->key.s = 0U;
	if (key == LETTER_KEY_RIGHT)
		game->key.d = 0U;
	if (key == ARROW_KEY_UP)
		game->key.arrow_u = 0U;
	if (key == ARROW_KEY_LEFT)
		game->key.arrow_l = 0U;
	if (key == ARROW_KEY_DOWN)
		game->key.arrow_d = 0U;
	if (key == ARROW_KEY_RIGHT)
		game->key.arrow_r = 0U;
	return (0);
}
