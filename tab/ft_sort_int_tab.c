/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:07:27 by abelov            #+#    #+#             */
/*   Updated: 2023/10/19 20:41:48 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

/**
 * difference-between-always-inline-and-inline:
 * 	https://stackoverflow.com/questions/20995309/
 * How do `move elimination` slots work in Intel CPU:
 * 	https://stackoverflow.com/questions/75204302/
 * See also:
 * 	https://en.wikipedia.org/wiki/XOR_swap_algorithm
 * 	https://chipsandcheese.com/2021/12/21/gracemont-revenge-of-the-atom-cores/
 */
static inline int	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *b;
	*b = *a;
	*a = temp;
	return (true);
}

/**
 * Bubble sort
 */
int	*ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	swapped;

	i = -1;
	while (++i < size - 1)
	{
		swapped = false;
		j = -1;
		while (++j < size - i - 1)
			if (tab[j] > tab[j + 1])
				swapped = ft_swap(&tab[j], &tab[j + 1]);
		if (!swapped)
			break ;
	}
	return (tab);
}
