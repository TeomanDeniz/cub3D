/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 01:53:10 by hdeniz            #+#    #+#             */
/*   Updated: 2024/03/08 01:53:12 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../cub3D.h" /*
#typedef *t_game;
#   void free_game(t_game);
#   void exit_game(t_game, int);
#*/
#include "../../libft/libft.h" /*
# size_t ft_strlen(char *);
#*/
#include <unistd.h> /*
#ssize_t write(int, void *, size_t);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	error_game(t_game game, const char *const error_message)
{
	write(2, "\n\n ", 3);
	write(2, error_message, ft_strlen(error_message));
	write(2, "\n\n", 2);
	exit_game(game, 1);
}
