/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:51:19 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/23 15:31:46 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [V] INCLUDES [V] **************************** */
#include "../libft.h" /*
#    int ft_strlen(const char *const);
#        */
#include <stdlib.h> /*
#   void *malloc(int);
#   void free(void *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

char
	*gnl_strchr(char *string, int character)
{
	register unsigned int	counter;

	counter = 0;
	if (!string)
		return (0);
	if (character == '\0')
		return ((char *)&string[ft_strlen(string)]);
	while (counter[string] != '\0')
	{
		if (counter[string] == (char) character)
			return ((char *)&string[counter]);
		++counter;
	}
	return (0);
}

char
	*gnl_strjoin(char *left_str, char *buff)
{
	register unsigned int	counter_1;
	register unsigned int	counter_2;
	char					*str;

	if (!left_str)
	{
		left_str = (char *) malloc(1 * sizeof(char));
		0[left_str] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	counter_1 = -1;
	counter_2 = 0;
	if (left_str)
		while (left_str[++counter_1] != '\0')
			str[counter_1] = left_str[counter_1];
	while (buff[counter_2] != '\0')
		str[counter_1++] = buff[counter_2++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

char
	*gnl_get_line(char *left_str)
{
	register int	counter;
	char			*str;

	counter = 0;
	if (!left_str[counter])
		return (NULL);
	while (left_str[counter] && left_str[counter] != '\n')
		++counter;
	str = (char *) malloc(sizeof(char) * (counter + 2));
	if (!str)
		return (NULL);
	counter = 0;
	while (left_str[counter] && left_str[counter] != '\n')
	{
		str[counter] = left_str[counter];
		++counter;
	}
	if (left_str[counter] == '\n')
	{
		str[counter] = left_str[counter];
		++counter;
	}
	str[counter] = '\0';
	return (str);
}

char
	*gnl_new_left_str(char *left_str)
{
	register int	counter_1;
	register int	counter_2;
	char			*str;

	counter_1 = 0;
	while (left_str[counter_1] && left_str[counter_1] != '\n')
		++counter_1;
	if (!left_str[counter_1])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - counter_1 + 1));
	if (!str)
		return (NULL);
	counter_2 = (++counter_1, 0);
	while (left_str[counter_1])
		str[counter_2++] = left_str[counter_1++];
	str[counter_2] = '\0';
	free(left_str);
	return (str);
}
