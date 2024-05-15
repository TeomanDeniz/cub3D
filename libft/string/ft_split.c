/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:23:24 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:23:27 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../libft.h" /*
#   char *ft_strchr(char *, int);
#    int ft_strlen(char *);
#   char *ft_strdup(char *);
#    int ft_free_matrix(char ***);
#   void *ft_calloc(size_t, size_t);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ int	split_get_word_count(const char *const string, \
register int character);
extern __inline__ void	split_get_next_word(char **string, \
register char character, register int index);
/* *************************** [^] PROTOTYPES [^] *************************** */

char
	**ft_split(const char *string, register char character)
{
	char			**result;
	register int	word;
	register int	index;

	index = -1;
	word = split_get_word_count((char *) string, character);
	result = ft_calloc(word + 1, sizeof(*result));
	if (result == NULL)
		return (NULL);
	while (++index < word)
	{
		split_get_next_word(((char **) &string), character, index);
		if (ft_strchr(string, character) == NULL)
			result[index] = ft_strdup(string);
		else
			result[index] = ft_substr(string, 0, \
				ft_strchr(string, character) - string);
		if (result[index] == NULL)
		{
			ft_free_matrix(&result);
			return (NULL);
		}
	}
	return (result);
}

extern __inline__ int
	split_get_word_count(const char *const string, register int character)
{
	register int	index;
	int				result;

	result = 0;
	index = 0;
	while (string[index] && string[index] == character)
		++index;
	while (string[index])
	{
		++result;
		while (string[index] && string[index] != character)
			++index;
		while (string[index] && string[index] == character)
			++index;
	}
	return (result);
}

extern __inline__ void
	split_get_next_word(char **string, register char character, \
register int index)
{
	if (index != 0)
	{
		while (**string && **string != character)
			(*string)++;
	}
	while (**string && **string == character)
		(*string)++;
}
