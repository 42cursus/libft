/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
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
 * returns the Nth element of the list,
 * assuming the first element of the list is when nbr equals 0.
 */
t_list	*ft_list_at(t_list *list, unsigned int nbr)
{
	t_list	*current;
	t_list	*next;

	if (!nbr)
		return (list);
	if (!list)
		return (NULL);
	current = list;
	while (current->next && nbr)
	{
		next = current->next;
		nbr--;
		current = next;
	}
	if (!nbr)
		return (current);
	return (NULL);
}
