/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:19:11 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:19:12 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int
	ft_tolower(int character)
{
	if (character >= 'A' && character <= 'Z')
		return (character + 32);
	return (character);
}
