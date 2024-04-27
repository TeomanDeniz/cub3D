/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:35:17 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:35:23 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int
	ft_isalpha(register int character)
{
	if ((character >= 'A' && character <= 'Z') || \
		(character >= 'a' && character <= 'z'))
		return (1);
	return (0);
}
