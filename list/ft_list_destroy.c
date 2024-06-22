/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:08:46 by abelov            #+#    #+#             */
/*   Updated: 2024/06/22 17:26:23 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

/**
 * Deletes and frees the given node and every successor of that node,
 * using the function 'del_fun' and free(3).
 *
 * Parameters:
 * 		list: The address of a first node.
 * 		del_fun: The address of the function used to delete the data content.
 */
void	ft_list_destroy(t_list **list, void (*del_fun)(void *))
{
	t_list	*current;
	t_list	*next;

	if (list != NULL)
	{
		current = *list;
		while (current != NULL)
		{
			next = current->next;
			if (del_fun != NULL)
				del_fun(current->data);
			free(current);
			current = next;
		}
	}
}
