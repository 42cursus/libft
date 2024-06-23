/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:35:51 by abelov            #+#    #+#             */
/*   Updated: 2024/06/23 20:36:01 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Byte-wise swap two items of size SIZE. */
static inline int	ft_qswap(void *a, void *b, size_t size)
{
	char	*var_a;
	char	*var_b;
	char	tmp;

	if (size > 0)
	{
		var_a = (char *) a;
		var_b = (char *) b;
		while (size-- > 0)
		{
			tmp = *var_a;
			*var_a++ = *var_b;
			*var_b++ = tmp;
		}
	}
	return (true);
}

void	ft_bsort(void *const base, size_t total_elems,
			size_t size, __compar_fn_t cmp)
{
	size_t	i;
	size_t	j;
	char	*left_ptr;
	char	*right_ptr;
	int		swapped;

	i = -1;
	while (++i < total_elems - 1)
	{
		swapped = false;
		j = -1;
		while (++j < total_elems - i - 1)
		{
			left_ptr = base + (j * size);
			right_ptr = base + ((j + 1) * size);
			if (cmp((void *) left_ptr, (void *) right_ptr) > 0)
				swapped = ft_qswap((void *) left_ptr,
						(void *) right_ptr, size);
		}
		if (!swapped)
			break ;
	}
}
