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
	if (key == SPACE_BAR)
		game->key.space = 1U;
	if (key == LETTER_KEY_UP)
		game->key.w = 1U;
	if (key == LETTER_KEY_LEFT)
		game->key.a = 1U;
	if (key == LETTER_KEY_DOWN)
		game->key.s = 1U;
	if (key == LETTER_KEY_RIGHT)
		game->key.d = 1U;
	if (key == ARROW_KEY_UP)
		game->key.arrow_u = 1U;
	if (key == ARROW_KEY_LEFT)
		game->key.arrow_l = 1U;
	if (key == ARROW_KEY_DOWN)
		game->key.arrow_d = 1U;
	if (key == ARROW_KEY_RIGHT)
		game->key.arrow_r = 1U;
	return (0);
}
