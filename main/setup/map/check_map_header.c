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
	if (check_map_header_color(map->f, "F") == -1)
		return (-1);
	if (check_map_header_color(map->c, "C") == -1)
		return (-1);
	return (0);
}

/*
	if (check_map_header_xpm(game, map->cd, "DC") == -1)
		return (-1);
*/

/*int
	check_map_header_door(t_game game) //
{
	register int	index;
	char			*str;
	t_image			*door;

	i = -1;
	while (++index, ++index < 48)
	{
		ft_asprintf(&str, "./textures/door/door_%.2d.xpm\0", index);
		if (str == NULL)
			return (ft_print_error("Memory allocation failed", "D2"));
		door = &game->doors[index];
		if (add_door_xpm_image(str, door, game->mlx, "D2") == -1)
		{
			free(str);
			return (-1);
		}
		free(str);
	}
	return (0);
}*/
