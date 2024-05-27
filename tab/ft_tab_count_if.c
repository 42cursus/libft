/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_count_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:51:48 by abelov            #+#    #+#             */
/*   Updated: 2024/05/27 00:27:57 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Function t_count_if returns the number of elements of the array
 * that return does not return 0 when passed to the function `f`
 */
int	ft_tab_count_if(void **tab, int length, int (*f)(void *))
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	if (!tab || !length)
		return (res);
	while (i < length)
		if (f(tab[i++]))
			res++;
	return (res);
}
