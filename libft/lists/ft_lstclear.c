/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:33:00 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:33:15 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../libft.h" /*
#typedef t_list;
#   void *ft_lstdelone(t_list *, void (*f)(void *));
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	ft_lstclear(t_list **list, void (*delete_event)(void *))
{
	t_list	*temp;

	if (!list || !delete_event || !*list)
		return ;
	while (list && *list)
	{
		temp = (*list)->next;
		ft_lstdelone(*list, delete_event);
		*list = temp;
	}
}
