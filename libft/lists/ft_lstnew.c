/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:30:17 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:30:45 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../libft.h" /*
#typedef t_list;
# t_list *ft_lstlast(t_list *);
#*/
#include <stdlib.h> /*
#   void *malloc(size_t);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

t_list
	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *) malloc(sizeof(t_list));
	if (!new_list)
		return (0);
	new_list->next = NULL;
	new_list->content = content;
	return (new_list);
}
