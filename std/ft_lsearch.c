/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsearch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:41:26 by abelov            #+#    #+#             */
/*   Updated: 2024/06/23 20:41:26 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <search.h>

/**
 * ft_lsearch_obj() performs a linear search for key in the array base which
 * 		has nmemb elements of size bytes each.
 * The comparison function referenced by compar is expected to have two
 * 		arguments which point to the key object  and  to  an
 * 		array member, in that order, and which returns zero if the key object
 * 		matches the array member, and nonzero otherwise.
 * If lsearch() does not find a matching element, then the key object is
 * 		inserted at the end of the table, and *nmemb is in‐
 * 		cremented.  In particular, one should know that a matching element
 * 		exists, or that more room is available.
 */
void	*ft_lsearch_obj(const void *key, t_obj_arr *obj)
{
	size_t		i;
	const void	*ptr;
	int			comparison;

	i = -1;
	while (++i < obj->total_elems)
	{
		ptr = (void *)(((const char *) obj->base)
				+ (i * obj->elem_size));
		comparison = (*obj->cmp_fun)(key, ptr);
		if (comparison == 0)
			return ((void *) ptr);
	}
	return (NULL);
}
