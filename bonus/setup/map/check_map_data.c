/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_data.c                                   :+:      :+:    :+:   */
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
#    int game_warning(char *, char *);
#        */
#include "../../../libft/libft.h" /*
#   char **ft_copy_matrix(char **);
#   char *ft_strchr(char *, int);
#    int ft_strlen(char *);
#        */
#include <stdio.h> /*
#    int printf(char *, ...);
#        */
#include "../../../libft/ft_math/ft_math.h" /*
# define M_PI_2_F
# define M_PI_F
# define M_PIX2_3_F
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	check_wall(const char **map);
extern __inline__ int	check_around(const char **map, \
register int x, register int y);
extern __inline__ int	check_player(t_game game, const char **map, \
int *arg_y, int *arg_x);
extern __inline__ void	set_player_direction(t_game game, \
register char player_dir);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	check_map_data(t_game game, t_map *map)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	if (map->map == NULL)
		return (game_warning("Empty map", NULL));
	if (check_player(game, (const char **)map->map, &y, &x) == -1)
		return (-1);
	game->x = (float)x + 0.5F;
	game->y = (float)y + 0.5F;
	if (check_wall((const char **)map->map) == -1)
		return (-1);
	game->map = (char **)ft_copy_matrix((const char **)map->map);
	if (game->map == NULL)
		return (game_warning("Malloc error", NULL));
	game->map[y][x] = '0';
	return (check_around((const char **)map->map, y, x));
}

extern __inline__ int
	check_player(t_game game, const char **map, int *arg_y, int *arg_x)
{
	register int	x;
	register int	y;

	y = -1;
	while (++y, map[y] != NULL)
	{
		x = -1;
		while (++x, map[y][x] != '\0')
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W'
				|| map[y][x] == 'E')
			{
				if (*arg_y != -1)
					return (game_warning("Duplicate player", NULL));
				*arg_y = y;
				*arg_x = x;
				set_player_direction(game, map[y][x]);
			}
		}
	}
	if (*arg_y == -1)
		return (game_warning("Player not found", NULL));
	return (0);
}

extern __inline__ void
	set_player_direction(t_game game, register char player_dir)
{
	if (player_dir == 'N')
		game->theta_rotation = 0.0F;
	else if (player_dir == 'S')
		game->theta_rotation = M_PI_2_F;
	else if (player_dir == 'E')
		game->theta_rotation = M_PI_F;
	else if (player_dir == 'W')
		game->theta_rotation = M_PIX2_3_F;
	game->theta_target_rotation = game->theta_rotation;
}

extern __inline__ int
	check_wall(const char **map)
{
	register int	x;
	register int	y;

	y = -1;
	while (++y, map[y] != NULL)
	{
		x = -1;
		while (++x, map[y][x] != '\0')
		{
			if (ft_strchr("0 1NSEWD\t\n", map[y][x]) == NULL)
			{
				printf("Invalid character [%c] at [%u][%u]", map[y][x], y, x);
				return (-1);
			}
			if ((map[y][x] == '0' || map[y][x] == 'D')
				&& check_around(map, y, x) == -1)
				return (-1);
		}
	}
	return (0);
}

extern __inline__ int
	check_around(const char **map, register int y, register int x)
{
	register int	result;

	result = 0;
	if (y == 0 || x == 0 || map[y + 1] == NULL || map[y][x + 1] == '\0')
		result = -1;
	else if ((signed int)ft_strlen(map[y - 1]) < x \
		|| ft_strchr("\n ", map[y - 1][x]) != NULL)
		result = -1;
	else if (ft_strchr("\n ", map[y][x - 1]) != NULL)
		result = -1;
	else if ((signed int)ft_strlen(map[y + 1]) < x
		|| ft_strchr("\n ", map[y + 1][x]) != NULL)
		result = -1;
	else if (ft_strchr("\n ", map[y][x + 1]) != NULL)
		result = -1;
	if (result == -1)
	{
		printf("Something is went wrong in the map at [%d][%d]", y, x);
		return (-1);
	}
	return (0);
}
