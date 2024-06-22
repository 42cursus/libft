/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_concat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:08:46 by abelov            #+#    #+#             */
/*   Updated: 2024/06/22 19:00:13 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_list.h"

/**
 * takes two lists and combines them into a single list.
 */
void	ft_list_concat(t_list **list1, t_list *list2)
{
	t_list	*last;

	if (list1 != NULL)
	{
		if (*list1)
		{
			last = ft_list_last(*list1);
			last->next = list2;
		}
		else
			*list1 = list2;
	}
}
