/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:40:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/04/20 14:40:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../cub3D.h" /*
#    int check_map_header_xpm(t_game, char *, char *);
#    int check_map_header_color(char *, char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	set_others(t_game game);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	check_map_header(t_game game, t_map *map)
{
	if (check_map_header_xpm(game, map->no, "NO") == -1)
		return (-1);
	if (check_map_header_xpm(game, map->so, "SO") == -1)
		return (-1);
	if (check_map_header_xpm(game, map->ea, "EA") == -1)
		return (-1);
	if (check_map_header_xpm(game, map->we, "WE") == -1)
		return (-1);
	if (check_map_header_xpm(game, map->door, "DC") == -1)
		return (-1);
	else
		set_others(game);
	if (check_map_header_color(map->f, "F") == -1)
		return (-1);
	if (check_map_header_color(map->c, "C") == -1)
		return (-1);
	return (0);
}

extern __inline__ void
	set_others(t_game game)
{
	register int	index;

	index = 4;
	while (++index, index < 9)
	{
		game->textures[index].buffer = game->textures[4].buffer;
		game->textures[index].x = game->textures[4].x;
		game->textures[index].y = game->textures[4].y;
		game->textures[index].endian = game->textures[4].endian;
		game->textures[index].line_length = game->textures[4].line_length;
		game->textures[index].bits_per_pixel = game->textures[4].bits_per_pixel;
	}
}
