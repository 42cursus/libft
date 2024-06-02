/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:59:36 by abelov            #+#    #+#             */
/*   Updated: 2024/05/19 17:59:37 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <stdbool.h>
#include <errno.h>
#include "ft_ctype.h"

static int		ft_strtol_check_base(int base, const char **str, int *c);
static void		ft_strtol_do_convert(int base, t_conv *res, int c,
					const char **str);
static void		ft_strtol_check_limits(int base, int c, t_conv *res);
static void		ft_strtol_check_result(t_conv *result, const char *nptr,
					char **endptr, char *saveptr);

/**
 * Converts the initial portion of the string
 * to their return type of long or long long
 */
long	ft_strtol(const char *nptr, char **endptr, register int base)
{
	int				c;
	char			*saveptr;
	t_conv *const	result = &(t_conv){.acc = 0, .any = 0, .neg = 1};

	saveptr = (char *)nptr;
	while (ft_isspace((unsigned char )*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*++nptr == '-')
			result->neg *= -1;
	c = (unsigned char )*nptr++;
	base = ft_strtol_check_base(base, &nptr, &c);
	ft_strtol_do_convert(base, result, c, &nptr);
	ft_strtol_check_result(result, nptr, endptr, saveptr);
	return ((long)result->acc);
}

void	ft_strtol_check_result(t_conv *result, const char *nptr,
						char **endptr, char *saveptr)
{
	if (result->any < 0)
	{
		result->acc = LONG_MAX;
		if (result->neg < 0)
			result->acc = LONG_MIN;
		errno = ERANGE;
	}
	else if (result->neg < 0)
		result->acc *= result->neg;
	if (endptr != NULL)
	{
		*endptr = saveptr;
		if (result->any)
			*endptr = (char *)(nptr - 1);
	}
}

void	ft_strtol_do_convert(int base, t_conv *res, int c, const char **str)
{
	res->cutoff = LONG_MAX;
	if (res->neg < 0)
		res->cutoff = -(unsigned long) LONG_MIN;
	res->cutlim = (int)(res->cutoff % (unsigned long)base);
	res->cutoff /= (unsigned long)base;
	while (true)
	{
		if (ft_isdigit((unsigned char) c) != 0)
			c -= '0';
		else if (ft_isalpha((unsigned char) c) != 0)
		{
			c = ft_tolower((unsigned char) c);
			c -= 'a' - 10;
		}
		else
			break ;
		if (c >= base)
			break ;
		ft_strtol_check_limits(base, c, res);
		c = *(*str)++;
	}
}

void	ft_strtol_check_limits(int base, int c, t_conv *res)
{
	if (res->any < 0 || res->acc > res->cutoff
		|| (res->acc == res->cutoff && c > res->cutlim))
		res->any = -1;
	else
	{
		res->any = 1;
		res->acc *= base;
		res->acc += c;
	}
}

int	ft_strtol_check_base(int base, const char **str, int *c)
{
	if ((base == 0 || base == 16)
		&& ((*c) == '0') && (*(*str) == 'x' || *(*str) == 'X') && (*str)++)
	{
		(*c) = *(*str)++;
		base = 16;
	}
	else if (base == 0)
	{
		base = 10;
		if ((*c) == '0')
			base = 8;
	}
	return (base);
}
