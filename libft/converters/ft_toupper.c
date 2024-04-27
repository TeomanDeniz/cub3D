/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:19:00 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:19:01 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int
	ft_toupper(int character)
{
	if (character >= 'a' && character <= 'z')
		return (character - 32);
	return (character);
}
