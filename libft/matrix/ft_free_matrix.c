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
#include <stdlib.h> /*
#   void free(void *);
#        */
#include <stdlib.h> /*
#typedef size_t;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	ft_free_matrix(char ***matrix)
{
	register size_t	index;

	if (!matrix || !*matrix)
		return (1);
	index = 0;
	while (!!(*matrix)[index])
	{
		free((*matrix)[index]);
		++index;
	}
	free(*matrix);
	*matrix = NULL;
	return (1);
}
