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
# include <stdbool.h> /*
# typedef bool;
# */
/* **************************** [^] INCLUDES [^] **************************** */
/* **************************** [v] STRUCTS [v] ***************************** */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
/* **************************** [^] STRUCTS [^] ***************************** */
/* ***************************** [v] ./bool [v] ***************************** */
extern int		ft_isalnum(register int character);
extern int		ft_isalpha(register int character);
extern int		ft_isascii(register int character);
extern int		ft_isdigit(register int character);
extern int		ft_isprint(register int character);
/* ***************************** [^] ./bool [^] ***************************** */
/* ************************** [v] ./converters [v] ************************** */
extern int		ft_atoi(const char *const string);
extern char		*ft_itoa(register int number);
extern int		ft_tolower(int character);
extern int		ft_toupper(int character);
/* ************************** [^] ./converters [^] ************************** */
/* **************************** [v] ./lists [v] ***************************** */
extern void		ft_lstadd_back(t_list **list, t_list *new_list);
extern void		ft_lstadd_front(t_list **list, t_list *new_list);
extern void		ft_lstclear(t_list **list, void (*delete_event)(void *));
extern void		ft_lstdelone(t_list *list, void (*delete_event)(void *));
extern void		ft_lstiter(t_list *list, void (*function)(void *));
extern t_list	*ft_lstlast(t_list *list);
extern t_list	*ft_lstmap(t_list *list, void *(*function)(void *), \
void (*delete_event)(void *));
extern t_list	*ft_lstnew(void *content);
extern int		ft_lstsize(t_list *list);
/* **************************** [^] ./lists [^] ***************************** */
/* **************************** [v] ./memory [v] **************************** */
extern void		ft_bzero(void *base, size_t index);
extern void		*ft_calloc(register size_t count, register size_t size);
extern bool		ft_free_matrix(char ***matrix);
extern void		*ft_memchr(const void *base, register int find, \
register size_t len);
extern int		ft_memcmp(const void *left, const void *right, size_t number);
extern void		*ft_memcpy(void *destination, const void *source, \
size_t number);
extern void		*ft_memmove(void *destination, const void *source, \
register size_t len);
extern void		*ft_memset(void *base, register int character, \
register size_t len);
extern bool		ft_safe_free(void **variable);
/* **************************** [^] ./memory [^] **************************** */
/* **************************** [v] ./output [v] **************************** */
extern void		ft_putchar_fd(char character, register int fd);
extern void		ft_putendl_fd(const char *const string, register int fd);
extern void		ft_putnbr_fd(register int number, register int fd);
extern void		ft_putstr_fd(const char *const string, register int fd);
/* **************************** [^] ./output [^] **************************** */
/* **************************** [v] ./string [v] **************************** */
extern size_t	ft_matrixrlen(char **matrix);
extern char		**ft_split(char const *const string, register char character);
extern bool		ft_strboolcmp(const char *const string, \
const char *const compare);
extern bool		ft_strcasecmp(const char *const string, \
const char *const compare);
extern char		*ft_strchr(const char *string, register int character);
extern char		ft_strcmp(const char *const string, const char *const compare);
extern char		*ft_strdup(const char *const string);
extern void		ft_striteri(const char *const string, \
void (*function)(unsigned int, char *));
extern char		*ft_strjoin(char const *const left, const char *const right);
extern size_t	ft_strlcat(char *const destination, const char *const source, \
register size_t destination_size);
extern size_t	ft_strlcpy(char *const destination, const char *const source, \
register size_t size);
extern size_t	ft_strlen(const char *const string);
extern char		*ft_strmapi(char const *const string, \
char (*function)(unsigned int, char));
extern int		ft_strncmp(const char *const left, const char *const right, \
register size_t index);
extern char		*ft_strnstr(const char *haystack, const char *const needle, \
register size_t len);
extern char		*ft_strrchr(const char *const string, register int character);
extern char		*ft_strtrim(char const *const left, char const *const right);
extern char		*ft_substr(char const *string, unsigned int start, size_t len);
/* **************************** [^] ./string [^] **************************** */
#endif /* LIBFT_H */
