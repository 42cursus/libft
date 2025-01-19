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

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format || !*format)
		return (0);
	va_start(ap, format);
	count = ft_vprintf(format, ap);
	va_end(ap);
	return (count);
}

int	ft_sprintf(char *str, const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = ft_vsprintf(str, format, ap);
	va_end(ap);
	return (count);
}

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = ft_vsnprintf(str, size, format, ap);
	va_end(ap);
	return (count);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (count);
}
