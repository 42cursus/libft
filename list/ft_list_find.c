/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:08:46 by abelov            #+#    #+#             */
/*   Updated: 2024/05/16 00:22:13 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_lists.h"

t_list	*ft_list_find(t_list *list, void *data_ref,
						int (*cmp)(void *, void *))
{
	t_list	*to_return;

	to_return = NULL;
	if (list != NULL)
	{
		while (list->next)
		{
			if (!cmp(list->data, data_ref))
			{
				to_return = list;
				break ;
			}
			list = list->next;
		}
		if (to_return != NULL && !cmp(list->data, data_ref))
			to_return = list;
	}
	return (to_return);
}
