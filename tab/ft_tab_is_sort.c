/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_is_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:09:44 by abelov            #+#    #+#             */
/*   Updated: 2024/05/27 00:28:50 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int	ft_string_tab_is_sort(char **tab, int (*f)(char *, char *))
{
	if (!tab || !*tab)
		return (true);
	if (!f)
		return (false);
	while (*++tab)
		if (f(*(tab - 1), *(tab)) > 0)
			return (false);
	return (true);
}

/**
 * returns 1 if the array is sorted and 0 if it isn't
 */
int	ft_tab_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (!tab || !length)
		return (true);
	if (!f)
		return (false);
	while (--length)
		if (f(tab[length - 1], tab[length]) < 0)
			return (false);
	return (true);
}
