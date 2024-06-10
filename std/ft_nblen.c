/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:04:25 by abelov            #+#    #+#             */
/*   Updated: 2024/06/10 16:04:25 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nblen(int nbr)
{
	int curr;
	int len;

	len = 0;
	curr = nbr;
	if ((nbr < 0) || (nbr == 0))
		len = 1;
	while (curr != 0)
	{
		curr = curr / 10;
		len++;
	}
	return len;
}