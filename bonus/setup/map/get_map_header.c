/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_header.c                                   :+:      :+:    :+:   */
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
#    int ft_strncmp(char *, char *, size_t);
#   char *ft_strdup(char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	get_data_header_line(char *line, char **dest, \
const char *const prefix);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	get_map_header(char *line, t_map *map)
{
	int	result;

	if (ft_strncmp(line, "NO ", 3) == 0)
		result = get_data_header_line(line + 3, &(map->no), "NO");
	else if (ft_strncmp(line, "SO ", 3) == 0)
		result = get_data_header_line(line + 3, &(map->so), "SO");
	else if (ft_strncmp(line, "WE ", 3) == 0)
		result = get_data_header_line(line + 3, &(map->we), "WE");
	else if (ft_strncmp(line, "EA ", 3) == 0)
		result = get_data_header_line(line + 3, &(map->ea), "EA");
	else if (ft_strncmp(line, "DC ", 3) == 0)
		result = get_data_header_line(line + 3, &(map->door), "DC");
	else if (ft_strncmp(line, "F ", 2) == 0)
		result = get_data_header_line(line + 2, &(map->f), "F");
	else if (ft_strncmp(line, "C ", 2) == 0)
		result = get_data_header_line(line + 2, &(map->c), "C");
	else if (line[0] == '\n')
		result = 0;
	else
		result = 1;
	return (result);
}

extern __inline__ int
	get_data_header_line(char *line, char **dest, const char *const prefix)
{
	if (*dest != NULL)
		return (game_warning("Duplicate data error for", prefix));
	*dest = ft_strdup(line);
	if (*dest == NULL)
		return (game_warning("Memory allocation failed", NULL));
	return (0);
}
