/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:31:04 by hdeniz            #+#    #+#             */
/*   Updated: 2022/12/06 16:31:25 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "../libft.h" /*
#typedef t_list;
# t_list *ft_lstnew(void *);
#   void ft_lstclear(t_list **, void (*f)(void *));
#   void ft_lstadd_back(t_list **, t_list *);
#*/
/* **************************** [^] INCLUDES [^] **************************** */

t_list
	*ft_lstmap(t_list *list, void *(*function)(void *), \
void (*delete_event)(void *))
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	while (list)
	{
		b = ft_lstnew(function(list->content));
		if (!b)
		{
			ft_lstclear(&a, delete_event);
			return (NULL);
		}
		ft_lstadd_back(&a, b);
		list = list->next;
	}
	return (a);
}
