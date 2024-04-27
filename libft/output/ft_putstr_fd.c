/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:23:40 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:24:41 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../libft.h" /*
# size_t ft_strlen(char *);
#*/
#include <unistd.h> /*
#ssize_t write(int, void *, size_t);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	ft_putstr_fd(const char *const string, register int fd);
{
	if (!string)
		return ;
	write(fd, string, ft_strlen(string));
}
