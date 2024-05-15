/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:18:46 by hdeniz            #+#    #+#             */
/*   Updated: 2024/03/06 13:45:18 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H 202403
/* **************************** [v] INCLUDES [v] **************************** */
# include <stdlib.h> /*
# typedef size_t;
# */
/* **************************** [^] INCLUDES [^] **************************** */
/* ***************************** [v] ./bool [v] ***************************** */
extern int		ft_isdigit(register int character);
/* ***************************** [^] ./bool [^] ***************************** */
/* ************************** [v] ./converters [v] ************************** */
extern int		ft_atoi(const char *const string);
extern int		ft_numlen(register int number);
/* ************************** [^] ./converters [^] ************************** */
/* **************************** [v] ./memory [v] **************************** */
extern void		ft_bzero(void *base, size_t index);
extern void		*ft_calloc(register size_t count, register size_t size);
extern void		*ft_memset(void *base, register int character, \
register size_t len);
/* **************************** [^] ./memory [^] **************************** */
/* **************************** [v] ./string [v] **************************** */
extern char		**ft_split(const char *string, register char character);
extern char		*ft_strchr(const char *string, register int character);
extern char		*ft_strdup(const char *const string);
extern size_t	ft_strlcpy(char *const destination, const char *const source, \
register size_t size);
extern size_t	ft_strlen(const char *const string);
extern int		ft_strncmp(const char *const left, const char *const right, \
register size_t index);
extern char		*ft_strtrim(char const *const left, char const *const right);
extern char		*ft_substr(char const *string, unsigned int start, size_t len);
/* **************************** [^] ./string [^] **************************** */
/* **************************** [v] ./matrix [v] **************************** */
extern char		**ft_copy_matrix(const char **map);
extern int		ft_matrixlen(const char **map);
extern int		ft_free_matrix(char ***matrix);
/* **************************** [^] ./matrix [^] **************************** */
#endif /* LIBFT_H */
