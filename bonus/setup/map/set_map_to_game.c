/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_to_game.c                                  :+:      :+:    :+:   */
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

extern __inline__ void	set_floor_ceiling_colors(t_game game, t_map map);

void
	set_map_to_game(t_game game, t_map map)
{
	set_floor_ceiling_colors(game, map);
}

extern __inline__ void
	set_floor_ceiling_colors(t_game game, t_map map)
{
	register unsigned char	red;
	register unsigned char	green;
	register unsigned char	blue;

	red = ft_atoi(map.f);
	green = ft_atoi(map.f + ft_numlen(red) + 1);
	blue = ft_atoi(map.f + ft_numlen(red) + ft_numlen(green) + 2);
	game->floor_color = (red << 16) + (green << 8) + (blue);
	red = ft_atoi(map.c);
	green = ft_atoi(map.c + ft_numlen(red) + 1);
	blue = ft_atoi(map.c + ft_numlen(red) + ft_numlen(green) + 2);
	game->ceiling_color = (red << 16) + (green << 8) + (blue);
}
