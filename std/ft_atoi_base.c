/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:14:34 by abelov            #+#    #+#             */
/*   Updated: 2024/05/25 17:27:11 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_string.h"

static t_uint	check_base_valid(char *base)
{
	char		*ptr;
	t_uint		ret;
	char const	*save = base;

	if (!base)
		return (0);
	while (*base)
	{
		if ((*base == '-') || (*base == '+') || ft_isspace(*base))
			return (0);
		ptr = base;
		while (*ptr++)
			if (*ptr == *base)
				return (0);
		base++;
	}
	ret = ft_strlen((char *)save);
	return (ret);
}

int	ft_atoi_base(char *str, char *base)
{
	int		integer;
	int		neg;
	int		digit;
	t_uint	radix;

	neg = 1;
	integer = 0;
	radix = check_base_valid(base);
	if (radix <= 0)
		return (0);
	while (*str && ft_isspace(*str))
		str++;
	while (*str && ((*str == '-') || (*str == '+')))
		if (*str++ == '-')
			neg *= -1;
	while (*str && ft_strchr(base, *str))
	{
		digit = (ft_strchr(base, *str++) - base);
		integer = digit + (integer * radix);
	}
	return (integer * neg);
}
