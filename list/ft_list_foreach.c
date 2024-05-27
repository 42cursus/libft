/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:08:46 by abelov            #+#    #+#             */
/*   Updated: 2024/05/16 00:22:13 by abelov           ###   ########.fr       */
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
void	ft_list_foreach(t_list *list, void (*f)(void *))
{
	if (!list || !f)
		return ;
	while (list->next)
	{
		f(list->data);
		list = list->next;
	}
	f(list->data);
}
