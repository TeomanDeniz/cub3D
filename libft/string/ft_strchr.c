/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:23:08 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:23:10 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char
	*ft_strchr(const char *string, register int character)
{
	if (!string)
		return (NULL);
	while (*string != (char)character && *string != '\0')
		++string;
	if (*string == '\0')
	{
		if (character != '\0')
			return (NULL);
		else
			return ((char *)string);
	}
	return ((char *)string);
}
