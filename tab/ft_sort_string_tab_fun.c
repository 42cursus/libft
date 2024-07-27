/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab_fun.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 05:53:03 by abelov            #+#    #+#             */
/*   Updated: 2024/05/22 05:53:04 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "ft_tab.h"

static inline int	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
	return (true);
}

/**
 * Bubble sort
 */
void	ft_sort_string_tab_fun(char **tab,
								int (*cmp)(const char *, const char *))
{
	int		i;
	int		j;
	size_t	size;
	int		swapped;

	size = ft_tab_get_size((void const **) tab);
	if (!tab || !*tab || ft_string_tab_is_sort(tab, cmp))
		return ;
	i = -1;
	while (++i < (int)(size - 1))
	{
		swapped = false;
		j = -1;
		while (++j < (int)(size - i - 1))
			if (cmp(*(tab + j), *(tab + j + 1)) > 0)
				swapped = ft_swap(tab + j, tab + j + 1);
		if (!swapped)
			break ;
	}
}
