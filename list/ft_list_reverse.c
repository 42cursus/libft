/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:08:46 by abelov            #+#    #+#             */
/*   Updated: 2024/05/16 00:22:13 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_list.h"

/**
 * reverses the order of a list’s elements.
 * The value of each element remains the same.
 */
void	ft_list_reverse(t_list **list)
{
	t_list	*current;
	t_list	*next;

	if (!list || !*list)
		return ;
	current = *list;
	next = current->next;
	current->next = NULL;
	while (next)
	{
		current = next;
		next = current->next;
		current->next = *list;
		*list = current;
	}
}
