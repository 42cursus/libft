/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_get_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:16:45 by abelov            #+#    #+#             */
/*   Updated: 2024/05/27 00:15:01 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_def.h"

t_uint	ft_tab_get_size(void const **tab)
{
	t_uint	size;

	size = 0;
	while (*tab && ++size)
		tab++;
	return (size);
}
