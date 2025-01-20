/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 03:23:13 by abelov            #+#    #+#             */
/*   Updated: 2025/01/17 03:23:14 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/param.h>
#include "libft.h"

size_t	ft_snprint_p(char **buf, size_t size, va_list *ap)
{
	size_t		i;
	char		*str;
	const void	*ptr = va_arg(*ap, void *);
	size_t		desired;

	str = ft_print_pointer((unsigned long long int) ptr);
	if (!str)
	{
		free(str);
		return (0);
	}
	i = ft_strlen(str);
	desired = MIN(i + FT_TERMINATOR, size);
	ft_memcpy(*buf, str, desired * sizeof(char));
	free(str);
	if (*buf)
		(*buf) += desired - 1;
	return (i);
}

size_t	ft_snprint_d(char **buf, size_t size, va_list *ap)
{
	size_t		i;
	char		str[20];
	size_t		desired;
	const int	nb = va_arg(*ap, int);

	ft_itoa_buf(nb, str, 20);
	i = ft_strlen(str);
	desired = MIN(i + FT_TERMINATOR, size);
	ft_memcpy(*buf, str, desired * sizeof(char));
	if (*buf)
		(*buf) += desired - 1;
	return (i);
}

size_t	ft_snprint_s(char **buf, size_t size, va_list *ap)
{
	size_t		i;
	const char	*str;
	size_t		desired;

	str = va_arg(*ap, char *);
	if (!str)
		str = STRPTRNULL;
	i = ft_strlen(str);
	desired = MIN(i + FT_TERMINATOR, size);
	ft_memcpy(*buf, str, desired * sizeof(char));
	if (*buf && desired)
		(*buf) += desired - 1;
	return (i);
}

size_t	ft_snprint_upperx(char **buf, size_t size, va_list *ap)
{
	size_t		i;
	char		*str;
	size_t		desired;
	const char	*base = "0123456789ABCDEF";

	str = ft_uitoa_base(va_arg(*ap, unsigned long), base);
	if (!str)
	{
		free(str);
		return (0);
	}
	i = ft_strlen(str);
	desired = MIN(i + FT_TERMINATOR, size);
	ft_memcpy(*buf, str, desired * sizeof(char));
	free(str);
	if (*buf && desired)
		(*buf) += desired - 1;
	return (i);
}

size_t	ft_snprint_x(char **buf, size_t size, va_list *ap)
{
	size_t		i;
	char		*str;
	size_t		desired;
	const char	*base = "0123456789abcdef";

	str = ft_uitoa_base(va_arg(*ap, unsigned long), base);
	if (!str)
	{
		free(str);
		return (0);
	}
	i = ft_strlen(str);
	desired = MIN(i + FT_TERMINATOR, size);
	ft_memcpy(*buf, str, desired * sizeof(char));
	free(str);
	if (*buf && desired)
		(*buf) += desired - 1;
	return (i);
}
