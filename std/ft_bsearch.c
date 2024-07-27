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

/**
 * The ft_bsearch_obj() function searches an array of `total_elems` objects,
 * 	the initial member of which is pointed to by `base`, for a member
 * 	that matches the object pointed to by key.
 * 	The size of each member of the array is specified by `elem_size`.
 * 	The  contents  of the array should be in ascending sorted order according
 * 	to the comparison function referenced by `cmp_fun`.
 * Accepts
 * 	struct s_object_arr
 * 	{
 * 		void *	base;
 * 		size_t	total_elems;
 * 		size_t	elem_size;
 * 		t_cmpf	cmp_fun;
 * 	};
 * Returns a pointer to a matching member of the array, or NULL
 * 	if  no match is found.
 */
void	*ft_bsearch_obj(const void *key, t_obj_arr *obj)
{
	size_t		lower;
	size_t		upper;
	size_t		idx;
	const void	*ptr;
	int			comparison;

	lower = 0;
	upper = obj->total_elems;
	while (lower < upper)
	{
		idx = (lower + upper) / 2;
		ptr = (void *)(((const char *) obj->base)
				+ (idx * obj->elem_size));
		comparison = (*obj->cmp_fun)(key, ptr);
		if (comparison < 0)
			upper = idx;
		else if (comparison > 0)
			lower = idx + 1;
		else
			return ((void *) ptr);
	}
	return (NULL);
}
