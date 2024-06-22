/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_replace_sublist.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:52:20 by abelov            #+#    #+#             */
/*   Updated: 2024/06/22 16:52:21 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	remove_nodes(t_list *parent, t_list *sub_list, void (*del_fun)(void *));

/**
 * removes every occurrence of sub-list from the given list
 */
void	ft_list_replace_sublist(t_list **list,
								t_list *const to_find,
								t_list *const to_replace_with,
								t_list_fun *lst_fun)
{
	t_list	*dummy;
	t_list	*tmp;
	t_list	*sub_head;
	t_list	*current;

	if (list != NULL && lst_fun != NULL && lst_fun->del_fun != NULL)
	{
		dummy = &(t_list){.next = *list};
		current = dummy;
		sub_head = to_find;
		while (current->next != NULL)
		{
			if (ft_list_starts_with(current->next, sub_head, lst_fun->cmp))
			{
				remove_nodes(current, sub_head, lst_fun->del_fun);
				tmp = ft_list_dup(to_replace_with);
				ft_list_concat(&tmp, current->next);
				current->next = tmp;
			}
			else
				current = current->next;
		}
		*list = dummy->next;
	}
}
