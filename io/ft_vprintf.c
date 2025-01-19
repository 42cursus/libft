/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 23:07:31 by abelov            #+#    #+#             */
/*   Updated: 2025/01/16 23:07:32 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/param.h>
#include "libft.h"

#ifdef USE_VSNPRINTF

int	ft_vprintf(const char *format, va_list ap)
{
	int		count;
	char	*string;
	va_list	ap_copy;

	va_copy(ap_copy, ap);
	count = ft_vsnprintf(NULL, 0, format, ap_copy);
	string = (char *) calloc(count + FT_TERMINATOR, sizeof(char));
	if (string)
	{
		ft_vsnprintf(string, count + FT_TERMINATOR, format, ap_copy);
		ft_putstr_fd(string, STDOUT_FILENO);
	}
	free(string);
	return (count);
}

#else

int	ft_vprintf(const char *format, va_list ap)
{
	int		count;
	va_list	ap_copy;

	va_copy(ap_copy, ap);
	count = ft_vdprintf(STDOUT_FILENO, format, ap_copy);
	return (count);
}

#endif

int	ft_vdprintf_internal(int fd, const char	*fmt, const t_printf_f *lut,
							va_list *ap)
{
	size_t				i;
	register char		c;

	i = 0;
	c = *fmt;
	while (c != '\0')
	{
		if (c != '%')
		{
			ft_putchar_fd(c, fd);
			i++;
			c = *++fmt;
			continue ;
		}
		c = *++fmt;
		if (c != '\0' && lut[(unsigned char) c])
			i += lut[(unsigned char) c](fd, ap);
		else
			fmt--;
		c = *++fmt;
	}
	return ((int)i);
}

int	ft_vdprintf(int fd, const char	*fmt, va_list ap)
{
	va_list				ap_save;
	static t_printf_f	lut[UCHAR_MAX] = {
	['c'] = ft_print_c,
	['%'] = ft_print_percent,
	['d'] = ft_print_d,
	['p'] = ft_print_p,
	['i'] = ft_print_d,
	['u'] = ft_print_u,
	['x'] = ft_print_x,
	['X'] = ft_print_upperx,
	['s'] = ft_print_s,
	};

	va_copy (ap_save, ap);
	return (ft_vdprintf_internal(fd, fmt, lut, &ap_save));
}
