/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:41:00 by hdeniz            #+#    #+#             */
/*   Updated: 2024/01/06 18:41:02 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
#   void free(void *);
#*/
#include <stdbool.h> /*
#typedef bool;
# define true;
#*/
/* **************************** [^] INCLUDES [^] **************************** */

bool
	ft_safe_free(void **variable)
{
	if (!variable || !*variable)
		return (true);
	free(*variable);
	*variable = NULL;
	return (true);
}
