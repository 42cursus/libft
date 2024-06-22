/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_ref.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:08:46 by abelov            #+#    #+#             */
/*   Updated: 2024/06/21 02:17:53 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/**
 * Iterates the list 'list' and applies the function 'f' on the content
 * of each node.
 *
 * Parameters:
 * 		list: The address of a pointer to a node.
 * 		f: The address of the function used to iterate on the list.
 */
void	ft_list_foreach_ref(t_list *list, void (*f)(void *, void *), void *ref)
{
	if (!list || !f)
		return ;
	while (list->next)
	{
		f(list->data, ref);
		list = list->next;
	}
	f(list->data, ref);
}
