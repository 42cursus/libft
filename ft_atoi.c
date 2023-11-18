/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:23:36 by abelov            #+#    #+#             */
/*   Updated: 2023/11/18 20:22:54 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_atoi() function converts the initial portion of the string pointed
 * to by nptr to int.
 */
int	ft_atoi(const char *nptr)
{
	int		neg;
	long	res;

	neg = 1;
	res = 0;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			neg *= -1;
	while (ft_isdigit(*nptr))
		res = res * 10 + *nptr++ - '0';
	return (neg * (int)res);
}
