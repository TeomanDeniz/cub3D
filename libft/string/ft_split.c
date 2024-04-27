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
#   char *ft_strdup(char *);
#   char *ft_substr(char *, uint, size_t);
#   bool ft_free_matrix(char ***);
#*/
#include <stdlib.h> /*
#typedef size_t;
#   void *malloc(size_t);
#   void free(void *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ size_t		ft_split__get_word_count(char *string, \
register char character);
extern __inline__ void			ft_split__get_next_word(char **string, \
register char character, register size_t index);
extern __inline__ char const	*ft_split__chr(char const *string, \
register char character);
/* *************************** [^] PROTOTYPES [^] *************************** */

char
	**ft_split(char const *string, register char character)
{
	char			**result;
	register size_t	word;
	register size_t	index;

	index = 0;
	word = ft_split__get_word_count((char *)string, character);
	result = (char **)malloc(sizeof(char *) * (word + 1));
	if (result == NULL)
		return (NULL);
	while (index < word)
	{
		ft_split__get_next_word(((char **) &string), character, index);
		if (ft_split__chr(string, character) == NULL)
			result[index] = ft_strdup(string);
		else
			result[index] = ft_substr(string, 0, \
				ft_split__chr(string, character) - string);
		if (result[index] == NULL)
		{
			ft_free_matrix(&result);
			return (NULL);
		}
		++index;
	}
	return (result);
}

extern __inline__ size_t
	ft_split__get_word_count(const char *const string, register char character)
{
	register size_t	index;
	size_t			result;

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
	ft_split__get_next_word(const char **string, register char character, \
size_t register index)
{
	if (index != 0)
	{
		while (**string && **string != character)
			++(*string);
	}
	while (**string && **string == character)
		++(*string);
}

extern __inline__ char const
	*ft_split__chr(char const *string, register char character)
{
	if (!string)
		return (NULL);
	while ((*string != '\0') && (*string != character))
		++string;
	if (*string == character)
		return (string);
	return (NULL);
}
