/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
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
#        */
#include <stdlib.h> /*
#   void free(void *);
#        */
#include "../../../libft/libft.h" /*
#    int ft_free_matrix(char ***);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	free_map(t_map *map)
{
	if (!!map->no)
		free(map->no);
	if (!!map->so)
		free(map->so);
	if (!!map->we)
		free(map->we);
	if (!!map->ea)
		free(map->ea);
	if (!!map->door)
		free(map->door);
	if (!!map->f)
		free(map->f);
	if (!!map->c)
		free(map->c);
	if (!!map->map)
		ft_free_matrix(&map->map);
}
