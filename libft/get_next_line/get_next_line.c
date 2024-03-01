/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:49:56 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/23 15:17:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "get_next_line.h" /*
# define BUFFER_SIZE 8
#   char *gnl_new_left_str(char *left_str);
#   char *gnl_strchr(char *string, int character);
#   char *gnl_strjoin(char *left_str, char *buff);
#   char *gnl_get_line(char *left_str);
*/
#include <stdlib.h> /*
# define NULL ((void *)0)
#   void *malloc(int);
#   void free(void *);
*/
#include <unistd.h> /*
#ssize_t read(int, void *, size_t);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static inline char	*gnl_get_file(register int fd, char *left_str);
/* *************************** [^] PROTOTYPES [^] *************************** */

char
	*get_next_line(register int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = gnl_get_file(fd, left_str);
	if (!left_str)
		return (NULL);
	line = gnl_get_line(left_str);
	left_str = gnl_new_left_str(left_str);
	return (line);
}

static inline char
	*gnl_get_file(register int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!gnl_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		rd_bytes[buff] = '\0';
		left_str = gnl_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}
