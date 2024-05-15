/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_header_xpm.c                             :+:      :+:    :+:   */
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
#    int ft_free_matrix(char ***);
#   char **ft_split(char *, char);
#   char *ft_strtrim(char *, char *);
#        */
#include "../../../minilibx/mlx.h" /*
#   void *mlx_xpm_file_to_image(void *, char *, int *, int *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	add_xpm_image(t_game game, char *line, \
const char *const prefix, register int index);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	check_map_header_xpm(t_game game, const char *const line, \
const char *const prefix)
{
	static int		texture_index = 0;
	char			*temp;
	char			**tab;
	register int	index;
	int				result;

	result = 0;
	temp = ft_strtrim(line, " \n");
	if (temp == NULL)
		return (game_warning("Memory allocation failed temp", prefix));
	tab = ft_split(temp, ' ');
	if (tab == NULL)
		result = game_warning("Memory allocation failed tab", prefix);
	index = -1;
	while (++index, tab[index] != NULL && result == 0)
		result = add_xpm_image(game, tab[index], prefix, texture_index);
	ft_free_matrix(&tab);
	free(temp);
	++texture_index;
	return (result);
}

extern __inline__ int
	add_xpm_image(t_game game, char *line, const char *const prefix, \
register int index)
{
	game->textures[index].image = mlx_xpm_file_to_image(game->mlx, line, \
		(signed *)&game->textures[index].x, (signed *)&game->textures[index].y);
	if (game->textures[index].image == NULL)
		return (game_warning("Invalid image path", prefix));
	game->textures[index].buffer = mlx_get_data_addr(\
		game->textures[index].image, &game->textures[index].bits_per_pixel, \
		&game->textures[index].line_length, &game->textures[index].endian);
	return (1);
}

//int
//	add_door_xpm_image(char *line, t_image *door, void *mlx, char *prefix)
//{
//	void	*img;
//	int		width;
//	int		height;
//
//	img = mlx_xpm_file_to_image(mlx, line, &width, &height);
//	if (img == NULL)
//		return (game_warning("Invalid image path", prefix));
//	door->image = img;
//	door->buffer = mlx_get_data_addr(img, &door->bits_per_pixel,
//			&door->line_length, &door->endian);
//	return (0);
//}
