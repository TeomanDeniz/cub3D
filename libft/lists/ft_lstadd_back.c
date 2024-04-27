/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:33:50 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:33:56 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../libft.h" /*
#typedef t_list;
# t_list *ft_lstlast(t_list *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	ft_lstadd_back(t_list **list, t_list *new_list)
{
	t_list	*last;

	if (!list)
		return ;
	if (!*list)
		*list = new_list;
	else
	{
		last = ft_lstlast(*list);
		last->next = new_list;
	}
}
