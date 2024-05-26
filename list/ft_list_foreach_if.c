/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:08:46 by abelov            #+#    #+#             */
/*   Updated: 2024/05/16 00:22:13 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/**
 * Iterates the list 'list' and applies the function 'f' on the data
 * of each node, which data cmp with data_ref, returns 0
 *
 * Parameters:
 * 		list: The address of a pointer to a node.
 * 		f: The address of the function used to iterate on the list.
 */
void	ft_list_foreach_if(t_list *list, void (*f)(void *), void *data_ref,
							int (*cmp)(void *, void *))
{
	if (!list || !f)
		return ;
	while (list->next)
	{
		if (!cmp(list->data, data_ref))
			f(list->data);
		list = list->next;
	}
	if (!cmp(list->data, data_ref))
		f(list->data);
}
