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

#include <stddef.h>
#include "ft_list.h"

static t_list	*ft_lst_get_next(t_list *list, const t_list **list_ptr)
{
	static t_list	*next = NULL;

	if (list)
		next = list;
	else
	{
		if (next && next->next)
			next = next->next;
		else
			next = NULL;
	}
	if (list_ptr)
		*list_ptr = next;
	return (next);
}

/**
 * Iterates the list 'list' and applies the function 'f' on the content
 * of each node, which content cmp with data_ref, returns 0
 *
 * Parameters:
 * 		list: The address of a pointer to a node.
 * 		f: The address of the function used to iterate on the list.
 */
void	ft_list_foreach_if(t_list *list, void (*f)(void *), void *data_ref,
			int (*cmp)(void *, void *))
{
	t_list const	*current = ft_lst_get_next(list, NULL);

	if (!list || !f)
		return ;
	while (ft_lst_get_next(NULL, &current))
		if (!cmp(current->data, data_ref))
			f(current->data);
}
