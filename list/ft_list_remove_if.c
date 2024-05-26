/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:08:46 by abelov            #+#    #+#             */
/*   Updated: 2024/05/16 00:22:13 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

/**
 * removes from the list, all elements whose data compared to data_ref
 * using cmp, makes cmp return 0.
 */
void	ft_list_remove_if(t_list **list, void *data_ref,
							int (*cmp)(void *, void *),
							void (*del_fun)(void *))
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	if (!list || !del_fun)
		return ;
	prev = *list;
	current = *list;
	while (current)
	{
		next = current->next;
		if (!(*cmp)(current->data, data_ref))
		{
			del_fun(current->data);
			if (prev == *list)
				*list = next;
			else
				prev->next = next;
			free(current);
			current = next;
		}
		prev = current;
		current = next;
	}
}
