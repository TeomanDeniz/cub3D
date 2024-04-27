/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:32:35 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:32:43 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../libft.h" /*
#typedef t_list;
#*/
#include <stdlib.h> /*
#   void free(void *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

void
	ft_lstdelone(t_list *list, void (*delete_event)(void *))
{
	if (!list || !delete_event)
		return ;
	delete_event(list->content);
	free(list);
}
