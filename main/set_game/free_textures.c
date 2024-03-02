/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:33:41 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/19 17:33:43 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../../minilibx/mlx.h" /*
#    int mlx_destroy_image(mlx_ptr_t *, mlx_img_list_t *);
*/
#include "../so_long.h" /*
#   void game_error(t_game, char *, char);
#typedef t_game;
*/
#include <unistd.h> /*
#ssize_t write(int, const void *, size_t);
*/
#include "../../libft/libft.h" /*
#   void ft_putnbr(register int number);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static inline void	free_textures_directly(t_game game);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	free_textures(t_game game_library, int id)
{
	free_textures_directly(game_library);
	if (id)
	{
		write(1, "Texture failed to open - ID[", 28);
		ft_putnbr(id);
		game_error(game_library, "]\n", 3);
	}
}

static inline void
	free_textures_directly(t_game game)
{
	if (!!game->texture_pack.ground)
		mlx_destroy_image(game->mlx, game->texture_pack.ground);
	if (game->texture_pack.wall)
		mlx_destroy_image(game->mlx, game->texture_pack.wall);
}
