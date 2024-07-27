/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_any.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:01:07 by abelov            #+#    #+#             */
/*   Updated: 2024/05/27 00:27:38 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_tab.h"

int	ft_tab_any(void const **tab, int (*f)(void *))
{
	t_uint	length;
	t_uint	i;

	i = 0;
	length = ft_tab_get_size(tab);
	if (!length)
		return (false);
	while (i < length)
		if (f((void *)tab[i++]))
			return (true);
	return (false);
}
