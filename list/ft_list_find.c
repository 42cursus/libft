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
#include "ft_list.h"

t_list	*ft_list_find(t_list *list, void *data_ref,
						int (*cmp)(void *, void *))
{
	if (!list)
		return (NULL);
	while (list->next)
	{
		if (!cmp(list->data, data_ref))
			return (list);
		list = list->next;
	}
	if (!cmp(list->data, data_ref))
		return (list);
	return (NULL);
}
