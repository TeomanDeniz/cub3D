/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:41:20 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/22 16:41:21 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../so_long.h" /*
#typedef t_game;
*/
#include <stdlib.h> /*
#   void free(void *);
*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	free_objects(t_game game)
{
	if (game->object.wall)
	{
		free(game->object.wall);
		game->object.wall = (void *)0;
	}
	if (game->object.barrier)
	{
		free(game->object.barrier);
		game->object.barrier = (void *)0;
	}
}
