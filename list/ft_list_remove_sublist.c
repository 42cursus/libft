/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_sublist.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:08:46 by abelov            #+#    #+#             */
/*   Updated: 2024/06/21 01:08:29 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	remove_nodes(t_list *parent, t_list *sub_list, void (*del_fun)(void *))
{
	t_list	*next;
	t_list	*current;

	current = parent->next;
	while (sub_list != NULL && current != NULL)
	{
		next = current->next;
		if (del_fun != NULL)
			del_fun(current->data);
		free(current);
		current = next;
		sub_list = sub_list->next;
	}
	parent->next = current;
}

/**
 * removes every occurrence of sub-list from the given list
 */
void	ft_list_remove_sublist(t_list **list, t_list *const	sub_list,
			__compar_fn_t cmp, void (*del_fun)(void *))
{
	t_list	*dummy;
	t_list	*current;

	if (list)
	{
		dummy = &(t_list){.next = *list};
		current = dummy;
		while (current->next != NULL)
		{
			if (ft_list_starts_with(current->next, sub_list, cmp))
				remove_nodes(current, sub_list, del_fun);
			else
				current = current->next;
		}
		*list = dummy->next;
	}
}
