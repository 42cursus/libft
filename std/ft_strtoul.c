/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:00:05 by abelov            #+#    #+#             */
/*   Updated: 2024/05/25 06:47:02 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdbool.h>
#include "ft_ctype.h"

int		ft_strtoul_check_base(int base, const char **str, int *c);
void	ft_strtoul_do_convert(int base, t_conv *res, int c, const char **str);
void	ft_strtoul_check_limits(int base, int c, t_conv *res);
void	ft_strtoul_check_result(t_conv *result,
			const char *nptr, char **endptr, char *saveptr);

unsigned long	ft_strtoul(const char *nptr, char **endptr, int base)
{
	int				c;
	char			*saveptr;
	t_conv *const	result = &(t_conv){.acc = 0, .any = 0, .neg = 1};

	saveptr = (char *)nptr;
	while (ft_isspace((unsigned char )*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*++nptr == '-')
			result->neg = -1;
	c = (unsigned char )*nptr++;
	base = ft_strtoul_check_base(base, &nptr, &c);
	ft_strtoul_do_convert(base, result, c, &nptr);
	ft_strtoul_check_result(result, nptr, endptr, saveptr);
	return (result->acc);
}

void	ft_strtoul_check_result(t_conv *result, const char *nptr, char **endptr,
								char *saveptr)
{
	if (result->any < 0)
		result->acc = ULONG_MAX;
	result->acc *= result->neg;
	if (endptr != NULL)
	{
		*endptr = saveptr;
		if (result->any)
			*endptr = (char *)(nptr - 1);
	}
}

void	ft_strtoul_do_convert(int base, t_conv *res, int c, const char **str)
{
	res->cutoff = (unsigned long)ULONG_MAX / (unsigned long)base;
	res->cutlim = (unsigned long)ULONG_MAX % (unsigned long)base;
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
		ft_strtoul_check_limits(base, c, res);
		c = *(*str)++;
	}
}

void	ft_strtoul_check_limits(int base, int c, t_conv *const res)
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

int	ft_strtoul_check_base(int base, const char **str, int *c)
{
	if ((base == 0 || base == 16)
		&& (*c == '0') && (*(*str) == 'x' || *(*str) == 'X') && (*str)++)
	{
		*c = *(*str)++;
		base = 16;
	}
	else if (base == 0)
	{
		base = 10;
		if (*c == '0')
			base = 8;
	}
	return (base);
}
