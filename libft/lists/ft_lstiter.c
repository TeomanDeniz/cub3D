/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:32:06 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:32:17 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../libft.h" /*
#typedef t_list;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	ft_lstiter(t_list *list, void (*function)(void *))
{
	if (!list || !function)
		return ;
	while (list != NULL)
	{
		function(list->content);
		list = list->next;
	}
}
