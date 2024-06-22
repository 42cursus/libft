/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_int_get_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:55:21 by abelov            #+#    #+#             */
/*   Updated: 2024/06/15 19:55:22 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tab_int_get_index(int const *tab, int start, int end, int to_find)
{
	int		i;

	i = start;
	while (i <= end)
	{
		if (tab[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_tab_int_contains(const int *tab, int size, int to_find)
{
	return (ft_tab_int_get_index(tab, 0, size - 1, to_find));
}
