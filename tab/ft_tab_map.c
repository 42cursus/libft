/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:33:02 by abelov            #+#    #+#             */
/*   Updated: 2024/05/27 00:29:02 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * Function ft_map applies a function on all elements of the given ints array
 * (in order) and returns an array of all the return values.
 */
int	*ft_tab_map(int *tab, int length, int (*f)(int))
{
	int	*new_array;
	int	i;

	i = -1;
	new_array = (int *)malloc (sizeof(int) * length);
	if (!new_array || !length || !tab)
		return (NULL);
	while (++i < length)
		new_array[i] = f(tab[i]);
	return (new_array);
}
