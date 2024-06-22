/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:08:46 by abelov            #+#    #+#             */
/*   Updated: 2024/06/21 02:28:24 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_list.h"

/**
 * Creates a copy of the list
 */
t_list	*ft_list_dup(t_list *list)
{
	t_list	*new;
	t_list	*current;

	new = NULL;
	if (list != NULL)
	{
		current = list;
		while (current)
		{
			ft_list_push_front(&new, current->data);
			current = current->next;
		}
		ft_list_reverse(&new);
	}
	else
		new = NULL;
	return (new);
}

/**
 * Creates a copy of the list
 */
t_list	*ft_list_dup_fun(t_list *list, void *(*dup_fun)(void *))
{
	t_list	*new;
	t_list	*current;

	new = NULL;
	if (list != NULL)
	{
		current = list;
		while (current)
		{
			ft_list_push_front(&new, dup_fun(current->data));
			current = current->next;
		}
		ft_list_reverse(&new);
	}
	else
		new = NULL;
	return (new);
}
