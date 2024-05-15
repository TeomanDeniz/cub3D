/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_header_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:40:55 by hdeniz            #+#    #+#             */
/*   Updated: 2024/04/20 14:40:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../../cub3D.h" /*
#    int game_warning(char *, char *);
#        */
#include "../../../libft/libft.h" /*
#    int ft_free_matrix(char ***);
#   char **ft_split(char *, char);
#   char *ft_strtrim(char *, char *);
#    int ft_atoi(char *);
#    int ft_strlen(char *);
#    int ft_isdigit(char);
#        */
#include <stdlib.h> /*
#   void free(void *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	check_comma(const char *const line);
extern __inline__ int	check_rgb_values(char **tab);
extern __inline__ int	check_string(const char *const line);
extern __inline__ int	check_digit(const char *const line);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	check_map_header_color(const char *const line, const char *const prefix)
{
	char	**tab;

	if (check_comma(line) != 2)
		return (game_warning("Invalid color format", prefix));
	tab = ft_split(line, ',');
	if (tab == NULL)
		return (game_warning("Memory allocation failed2", NULL));
	if (tab[0] == NULL || tab[1] == NULL || tab[2] == NULL || tab[3] != NULL)
	{
		ft_free_matrix(&tab);
		return (game_warning("Invalid color format", prefix));
	}
	if (check_rgb_values(tab) == -1)
	{
		ft_free_matrix(&tab);
		return (game_warning("Invalid color value", prefix));
	}
	ft_free_matrix(&tab);
	return (0);
}

extern __inline__ int
	check_comma(const char *const line)
{
	register int	index;
	int				count;

	index = -1;
	count = 0;
	while (++index, line[index] != '\0')
		if (line[index] == ',')
			++count;
	return (count);
}

extern __inline__ int
	check_rgb_values(char **tab)
{
	register int	index;
	register int	result;
	char			*temp;
	int				value;

	value = 0;
	index = -1;
	result = 0;
	while (++index, tab[index] != NULL)
	{
		temp = ft_strtrim(tab[index], " \n");
		if (temp == NULL)
			return (game_warning("Memory allocation failed for temp", NULL));
		result = check_string(temp);
		free(temp);
		if (result == -1)
			return (-1);
		value = ft_atoi(tab[index]);
	}
	return (value);
}

extern __inline__ int
	check_string(const char *const line)
{
	register int	index;
	long			value;

	index = 0;
	if (line[0] == '-')
		++index;
	if (ft_strlen(line + index) == 0)
		return (-1);
	while (line[index] == '0')
		++index;
	if (check_digit(line + index) == -1)
		return (-1);
	if (ft_strlen(line + index) > 4)
		return (-1);
	value = ft_atoi(line);
	if (value > 255 || value < 0)
		return (-1);
	return (value);
}

extern __inline__ int
	check_digit(const char *const line)
{
	register int	index;

	index = 0;
	while (line[index] && ft_isdigit(line[index]))
		++index;
	if (line[index])
		return (-1);
	return (0);
}
