/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:23:24 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:23:27 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include <stdlib.h> /*
#   void *malloc(int);
*/
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [V] PROTOTYPES [V] *************************** */
static int	count_words(char const *s, char c);
static char	*make_words(char *word, char const *s, int j, int word_ln);
static char	**split_words(char **res, char const *s, char c, int word_ct);
/* *************************** [^] PROTOTYPES [^] *************************** */

char
	**ft_split(char const *s, char c)
{
	int		word_ct;
	char	**res;

	if (s == 0)
		return (0);
	word_ct = count_words(s, c);
	res = (char **) malloc(sizeof(char *) * (word_ct + 1));
	if (!res)
		return (0);
	split_words (res, s, c, word_ct);
	return (res);
}

static int
	count_words(char const *s, char c)
{
	register int	i;
	register int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			++i;
		else
		{
			++count;
			while (s[i] && s[i] != c)
				++i;
		}
	}
	return (count);
}

static char
	*make_words(char *word, char const *s, int j, int word_ln)
{
	register int	i;

	i = 0;
	while (word_ln > 0)
		word[i++] = s[j - word_ln--];
	word[i] = 0;
	return (word);
}

static char
	**split_words(char **res, char const *s, char c, int word_ct)
{
	register int	i;
	register int	j;
	register int	word_ln;

	i = 0;
	j = 0 ;
	word_ln = 0;
	while (s[j] && i < word_ct)
	{
		while (s[j] && s[j] == c)
			++j;
		while (s[j] && s[j] != c)
			j += (++word_ln, 1);
		res[i] = (char *) malloc(sizeof(char) * (word_ln + 1));
		if (!res[i])
			return (0);
		make_words (res[i], s, j, word_ln);
		word_ln = (++i, 0);
	}
	res[i] = 0;
	return (res);
}
