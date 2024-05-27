/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
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
 * Deletes and frees the given node and every successor of that node,
 * using the function 'del_fun' and free(3).
 *
 * Parameters:
 * 		list: The address of a first node.
 * 		del_fun: The address of the function used to delete the data content.
 */
void	ft_list_clear(t_list *list, void (*del_fun)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!list || !del_fun)
		return ;
	current = list;
	while (current)
	{
		next = current->next;
		del_fun(current->data);
		free(current);
		current = next;
	}
}
