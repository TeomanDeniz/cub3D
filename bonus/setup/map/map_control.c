/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
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
#typedef t_map;
#    int check_map_header(t_game, t_map *);
#    int check_map_data(t_game, t_map *);
#    int game_warning(char *, char *);
#   void set_map_to_game(t_game, t_map);
#   void free_map(t_map *);
#   void map_extension(char *);
#        */
#include <fcntl.h> /*
# define O_RDONLY
#    int open(char *, int, ...);
#        */
#include <unistd.h> /*
#    int close(int);
#        */
#include <string.h> /*
#   char *strerror(int);
^------> <errno.h>
#        */
#include <errno.h> /*
@<------ <string.h> REQUIRED
G    int errno;
#        */
#include "../../../libft/get_next_line/get_next_line.h" /*
#   char *get_next_line(int);
#        */
#include "../../../libft/libft.h" /*
#   void ft_bzero(void *, size_t);
#    int ft_strlen(char *);
#    int ft_matrixlen(char **);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	open_map_file(const char *cub_file, t_map *map);
extern __inline__ int	read_file(register int fd, t_map *map, int result);
extern __inline__ int	is_missing_data(t_map *map);
extern __inline__ int	skip_empty_line(const char *const line);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	map_control(t_game game, const char *cub_file)
{
	t_map	map;

	map.no = NULL;
	map.so = NULL;
	map.we = NULL;
	map.ea = NULL;
	map.door = NULL;
	map.f = NULL;
	map.c = NULL;
	map.map = NULL;
	if (open_map_file(cub_file, &map) == -1 || \
		check_map_header(game, &map) == -1 || \
		check_map_data(game, &map) == -1)
		return (-1);
	game->map_width = ft_strlen(*game->map);
	game->map_height = ft_matrixlen((const char **)game->map);
	set_map_to_game(game, map);
	free_map(&map);
	return (1);
}

extern __inline__ int
	open_map_file(const char *cub_file, t_map *map)
{
	register int	fd;
	int				result;

	if (map_extension(cub_file) == -1)
		return (-1);
	fd = open(cub_file, O_RDONLY);
	if (fd == -1)
	{
		game_warning(strerror(errno), NULL);
		return (-1);
	}
	result = read_file(fd, map, 0);
	close(fd);
	return (result);
}

extern __inline__ int
	read_file(register int fd, t_map *map, int result)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		game_warning("Read error on first line of the cub file!", NULL);
		return (-1);
	}
	while (line != NULL)
	{
		if (result == 0)
			result = get_map_header(line, map);
		if (result == 1)
			result = is_missing_data(map);
		if (result == 2)
			result = skip_empty_line(line);
		if (result == 3)
			result = get_data_map(line, map);
		free(line);
		line = get_next_line(fd);
	}
	if (result == 0)
		result = is_missing_data(map);
	return (result);
}

extern __inline__ int
	is_missing_data(t_map *map)
{
	char	*prefix;

	prefix = NULL;
	if (map->no == NULL)
		prefix = "NO";
	else if (map->so == NULL)
		prefix = "SO";
	else if (map->we == NULL)
		prefix = "WE";
	else if (map->ea == NULL)
		prefix = "EA";
	else if (map->door == NULL)
		prefix = "DC";
	else if (map->f == NULL)
		prefix = "F";
	else if (map->c == NULL)
		prefix = "C";
	if (prefix != NULL)
		return (game_warning("Missing data", prefix));
	return (2);
}

extern __inline__ int
	skip_empty_line(const char *const line)
{
	if (line[0] == '\n')
		return (2);
	return (3);
}
