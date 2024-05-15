/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_map.c                                   	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:40:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/04/20 14:40:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../cub3D.h" /*
#typedef t_map;
#    int game_warning(char *, char *);
#        */
#include "../../../libft/libft.h" /*
#    int ft_matrixlen(char **);
#   void *ft_calloc(size_t, size_t);
#   char *ft_strdup(char *);
#    int ft_free_matrix(char ***);
#        */
#include <stdlib.h> /*
#   void free(void *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	get_data_map(const char *const line, t_map *map)
{
	char			**new_map;
	register int	index;

	new_map = (char **)ft_calloc(\
		ft_matrixlen((const char **)map->map) + 2, sizeof(char *));
	if (new_map == NULL)
		return (game_warning("Memory allocation failed", NULL));
	index = 0;
	while (map->map && map->map[index] != NULL)
	{
		new_map[index] = map->map[index];
		++index;
	}
	new_map[index] = ft_strdup(line);
	if (new_map[index] == NULL)
	{
		ft_free_matrix(&new_map);
		return (game_warning("Memory allocation failed5", NULL));
	}
	free(map->map);
	map->map = new_map;
	return (3);
}
