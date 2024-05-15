/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_warning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:27:45 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:28:28 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include <unistd.h> /*
#ssize_t write(int, void *, size_t);
#        */
#include "../../libft/libft.h" /*
#    int ft_strlen(char *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

int
	game_warning(const char *const message, const char *const prefix)
{
	if (!prefix)
	{
		write(2, "Error - Reason: ", 16);
		write(2, message, ft_strlen(message));
	}
	else
	{
		write(2, "Error - Reason: ", 16);
		write(2, message, ft_strlen(message));
		write(2, " ", 1);
		write(2, prefix, ft_strlen(prefix));
	}
	write(2, "\n", 1);
	return (-1);
}
