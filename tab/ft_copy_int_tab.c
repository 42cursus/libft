/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:59:18 by abelov            #+#    #+#             */
/*   Updated: 2024/06/10 20:09:38 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_copy_int_tab(const int *src, int *dst, int start, int end)
{
	int	i;

	i = 0;
	while (i < end - start + 1)
	{
		dst[i] = src[start + i];
		i++;
	}
	return (dst);
}
