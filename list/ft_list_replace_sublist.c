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
#include "ft_string.h"
#include "ft_list.h"

void	remove_nodes(t_list *parent, t_list *sub_list, void (*del_fun)(void *));

void	ft_list_do_replace(t_list *to_replace_with, t_list_fun *lst_fun,
			t_list *sub_head, t_list *current);

/**
 * removes every occurrence of sub-list from the given list
 */
void	ft_list_replace_sublist(t_list **list,
								t_list *const to_find,
								t_list *const to_replace_with,
								t_list_fun *lst_fun)
{
	t_list	*dummy;
	t_list	*sub_head;
	t_list	*current;

	if (list != NULL && lst_fun != NULL)
	{
		dummy = &(t_list){.next = *list};
		current = dummy;
		sub_head = to_find;
		while (current->next != NULL)
		{
			if (ft_list_starts_with(current->next, sub_head, lst_fun->cmp_fun))
				ft_list_do_replace(to_replace_with, lst_fun, sub_head, current);
			else
				current = current->next;
		}
		*list = dummy->next;
	}
}

void	ft_list_do_replace(t_list *const to_replace_with, t_list_fun *lst_fun,
				t_list *sub_head, t_list *current)
{
	t_list	*tmp;

	remove_nodes(current, sub_head, lst_fun->del_fun);
	if (lst_fun->dup_fun == NULL)
		tmp = ft_list_dup(to_replace_with);
	else
		tmp = ft_list_dup_fun(to_replace_with, lst_fun->dup_fun);
	ft_list_concat(&tmp, current->next);
	current->next = tmp;
}
