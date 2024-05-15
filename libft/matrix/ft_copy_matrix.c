/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:46:51 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/17 13:46:52 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../libft.h" /*
#    int ft_strlen(char *);
#    int ft_free_matrix(char **);
#        */
#include <stdlib.h> /*
#   void *malloc(int);
#   void free(void *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

char
	**ft_copy_matrix(const char **map)
{
	register int	max_y;
	register int	y;
	register int	x;
	char			**result;

	max_y = 0;
	while (map[max_y])
		++max_y;
	result = (char **)malloc(sizeof(char *) * (max_y + 1));
	if (!result)
		return ((void *)0);
	y = -1;
	while (++y, y < max_y)
	{
		result[y] = (char *)malloc(sizeof(char) * (ft_strlen(map[y]) + 1));
		if (!result[y])
			return (ft_free_matrix(&result), (void *)0);
		x = -1;
		while (++x, map[y][x])
			result[y][x] = map[y][x];
		result[y][x] = 0;
	}
	result[y] = ((void *)0);
	return (result);
}
