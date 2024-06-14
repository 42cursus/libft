/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:53:13 by abelov            #+#    #+#             */
/*   Updated: 2024/06/10 19:53:13 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

int	*ft_init_int_tab(int len)
{
	int	i;
	int	*tab;

	i = 0;
	if (len <= 0)
		return (NULL);
	tab = (int *)malloc(sizeof(int) * len);
	if (!tab)
		return (NULL);
	while (i < len)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
