/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find_sublist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:08:46 by abelov            #+#    #+#             */
/*   Updated: 2024/06/22 16:10:24 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "ft_list.h"

int	ft_list_starts_with(t_list *head, t_list *sub, __compar_fn_t cmp)
{
	int	ret_val;

	ret_val = 1;
	while (sub != NULL)
	{
		if (head == NULL || cmp(head->data, sub->data))
		{
			ret_val = 0;
			break ;
		}
		head = head->next;
		sub = sub->next;
	}
	return (ret_val);
}

t_list	*ft_list_find_sublist(t_list *list, t_list *const sub_list,
								__compar_fn_t cmp)
{
	t_list	*to_return;
	t_list	*sub_head;
	t_list	*current;

	to_return = NULL;
	if (list != NULL)
	{
		current = list;
		sub_head = sub_list;
		while (current->next != NULL)
		{
			if (ft_list_starts_with(current->next, sub_head, cmp))
			{
				to_return = current->next;
				break ;
			}
			else
				current = current->next;
		}
	}
	return (to_return);
}
