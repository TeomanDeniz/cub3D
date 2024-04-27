/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:37:22 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/06 21:37:23 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../libft.h" /*
#   bool ft_safe_free(char **);
#*/
#include <stdlib.h> /*
#   void free(void *);
#*/
#include <stdlib.h> /*
#typedef size_t;
#*/
#include <stdbool.h> /*
#typedef bool;
# define true;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

bool
	ft_free_matrix(char ***matrix)
{
	register size_t	index;

	if (!matrix || !*matrix)
		return (true);
	index = 0;
	while (!!(*matrix)[index])
	{
		ft_safe_free((void **)index[&(*matrix)]);
		++index;
	}
	free(*matrix);
	*matrix = NULL;
	return (true);
}
