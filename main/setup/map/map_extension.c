/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:40:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/04/20 14:40:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../cub3D.h" /*
#typedef t_game;
#    int game_warning(char *, char *);
#        */
#include "../../../libft/libft.h" /*
#    int ft_strlen(char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	map_extension(const char *file)
{
	register int	string_size;

	if (!file)
		return (game_warning("How the heck is file variable null???", NULL));
	string_size = ft_strlen(file);
	if (string_size < 5)
		return (game_warning("Name is a litle strange. A little short", NULL));
	if (file[string_size - 1] == 'b' && file[string_size - 2] == 'u' && \
		file[string_size - 3] == 'c' && file[string_size - 4] == '.')
		return (1);
	game_warning("The file extension is not \".cub\" file!", file);
	return (-1);
}
