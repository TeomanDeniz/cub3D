/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:06:13 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/19 16:15:25 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 202309

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

extern char	*gnl_new_left_str(char *left_str);
extern char	*gnl_strchr(char *string, int character);
extern char	*gnl_strjoin(char *left_str, char *buff);
extern char	*gnl_get_line(char *left_str);
extern char	*get_next_line(int fd);

#endif /* GET_NEXT_LINE_H */