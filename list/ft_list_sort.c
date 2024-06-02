/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:08:46 by abelov            #+#    #+#             */
/*   Updated: 2024/05/16 00:22:13 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include "ft_list.h"

/**
 * Swapping two nodes usually takes five operations:
 * 	   Change the node one back from the first node to point to the second node.
 * 	   Change the node one back from the second node to point to the first node.
 * 	   Store the first node's next pointer in a temporary pointer.
 * 	   Change the first node's next pointer to the second node's next pointer.
 * 	   Change the second node's next pointer to the temporary pointer.
 * Swapping two variables takes at least three operations:
 *     Store the first variable in a temporary variable.
 *     Change the first variable to the second variable.
 *     Change the second variable to the first variable.
 * See also:
 * 	Sorting a linked list via copying its values or via relinking the nodes
 * 		https://cs.stackexchange.com/questions/117557/
 * 	Sorting Linked Lists - move nodes or swap data members
 * 		https://stackoverflow.com/questions/37475405/
 */
static int	ft_list_swap(t_list *p1, t_list *p2)
{
	t_list_swap	swap;

	swap.el1 = p1->next;
	swap.el2 = p2->next;
	p1->next = swap.el2;
	p2->next = swap.el1;
	swap.tmp = swap.el1->next;
	swap.el1->next = swap.el2->next;
	swap.el2->next = swap.tmp;
	return (true);
}

/**
 * `ft_list_sort` sorts the list's elements by ascending order
 * 	by comparing two elements by comparing their data with a function.
 *
 * 	Hint:
 * 		function argument is a double pointer that implies that we are to sort
 * 		list elements and not their data values.
 */
void	ft_list_sort(t_list **list, int (*cmp)(void *, void *))
{
	int				size;
	int				swapped;
	t_list *const	head = &(t_list){.next = NULL};
	t_iter *const	it = &(t_iter){.i = -1, .j = -1};
	t_list			*curr;

	if (!list || !*list || !(*list)->next)
		return ;
	head->next = *list;
	size = ft_list_size(*list);
	while (++(it->i) < size - 1)
	{
		swapped = false;
		it->j = -1;
		curr = head;
		while (++(it->j) < size - it->i)
		{
			if (cmp(curr->next->data, curr->next->next->data) > 0)
				swapped = ft_list_swap(curr, curr->next);
			curr = curr->next;
		}
		if (!swapped)
			break ;
	}
	*list = head->next;
}
