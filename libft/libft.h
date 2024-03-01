/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:18:46 by hdeniz            #+#    #+#             */
/*   Updated: 2023/08/08 15:48:48 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H 20230814

extern int	ft_strlen(const char *const string);
extern char	*ft_strdup(const char *string);
extern char	*get_next_line(register int fd);
extern int	ft_rand(int min, int max);
extern int	ft_strlcat(char	*dst, const char *src, int dstsize);
extern char	*ft_strjoin(char const *s1, const char *s2);
extern int	ft_strlcpy(char *dst, const char *src, int size);
extern char	**ft_split(char const *s, char c);
extern void	ft_putnbr(register int number);
extern void	ft_free_matrix(char **matrix);
extern char	**ft_copy_matrix(char **map);
extern void	ft_print_matrix(char **matrix);
extern int	ft_matrixrlen(char **matrix);
extern int	ft_numlen(register int number);

#endif /* LIBFT_H */
