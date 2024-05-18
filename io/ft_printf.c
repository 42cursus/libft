/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 00:46:08 by abelov            #+#    #+#             */
/*   Updated: 2023/12/05 00:46:11 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
}

int	do_print(const char	*fmt, va_list *argp,
				void (*putc)(char),
				t_ft_print_dispatch_f const	ft_print_dispatch[])
{
	size_t					i;
	register char			c;

	i = 0;
	c = *fmt;
	while (c != '\0')
	{
		if (c != '%')
		{
			(*putc)(c);
			i++;
			c = *++fmt;
			continue ;
		}
		c = *++fmt;
		if (c != '\0' && ft_print_dispatch[(unsigned char) c])
			i += ft_print_dispatch[(unsigned char) c](argp);
		else
			fmt--;
		c = *++fmt;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list								args;
	char								*str;
	int									count;
	static t_ft_print_dispatch_f const	ft_print_dispatch[UCHAR_MAX] = {
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

	if (!format || !*format)
		return (0);
	str = ft_strdup((char *)format);
	if (!str || *str == '\0')
		return (0);
	va_start(args, format);
	count = do_print(str, &args, ft_putchar, ft_print_dispatch);
	va_end(args);
	free(str);
	return (count);
}
