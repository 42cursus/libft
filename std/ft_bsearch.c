/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsearch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:41:26 by abelov            #+#    #+#             */
/*   Updated: 2024/06/23 20:41:26 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bsearch(const void *key, t_object_arr *object_arr,
			__compar_fn_t cmp)
{
	size_t		lower;
	size_t		upper;
	size_t		idx;
	const void	*ptr;
	int			comparison;

	lower = 0;
	upper = object_arr->total_elems;
	while (lower < upper)
	{
		idx = (lower + upper) / 2;
		ptr = (void *)(((const char *) object_arr->base)
				+ (idx * object_arr->size));
		comparison = (*cmp)(key, ptr);
		if (comparison < 0)
			upper = idx;
		else if (comparison > 0)
			lower = idx + 1;
		else
			return ((void *) ptr);
	}
	return (NULL);
}
