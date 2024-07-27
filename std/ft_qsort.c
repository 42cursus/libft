/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:53:37 by abelov            #+#    #+#             */
/*   Updated: 2024/06/23 16:53:38 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qsort(void *const base, size_t total_elems,
					size_t size, __compar_fn_t cmp)
{
	ft_bsort(base, total_elems, size, cmp);
}

void	ft_qsort_obj(t_obj_arr *obj)
{
	ft_qsort(obj->base, obj->total_elems, obj->elem_size, obj->cmp_fun);
}
