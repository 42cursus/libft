/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_create_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:23:54 by abelov            #+#    #+#             */
/*   Updated: 2024/05/27 00:39:16 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_lists.h"

/**
 * Allocates (with malloc(3)) and returns a new list node.
 * The member variable 'data' is initialized with the value of the parameter
 * 'data'. The variable 'next' is initialized to NULL.
 */
t_list	*ft_list_create_elem(void *data)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(*elem));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

t_list	*ft_lstnew(void *data)
{
	return (ft_list_create_elem(data));
}
