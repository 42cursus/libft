/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 05:11:22 by abelov            #+#    #+#             */
/*   Updated: 2025/01/19 05:11:23 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/param.h>
#include "libft.h"

int	ft_vsprintf(char *str, const char *format, va_list ap)
{
	int	result;

	result = ft_vsnprintf(NULL, 0, format, ap);
	if (result < 0)
		return (FT_ERROR);
	return (ft_vsnprintf(str, (size_t)result + 1, format, ap));
}

char	*ft_strchrnul(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char) *s == (unsigned char) c)
			break ;
		s++;
	}
	return ((char *)s);
}

size_t	copy_as_is(size_t size, const char **fmt, char **buf)
{
	const char *const	ptr = ft_strchrnul((*fmt), '%');
	const size_t		i = ptr - (*fmt);
	const size_t		desired = MIN(i + FT_TERMINATOR, size);
	char *const			to_put = ft_strndup((*fmt), i);

	ft_memcpy((*buf), to_put, desired * sizeof(char));
	free(to_put);
	(*fmt) = (ptr - 1);
	if (*buf)
		(*buf) += desired - 1;
	return (i);
}

int	ft_vsnprintf_internal(char *(*str)[2], size_t size, const t_snprintf_f *lut,
							va_list *ap)
{
	size_t			ret;
	register char	c;
	char			*buf;
	const char		*fmt = (*str)[0];
	char *const		dst = (*str)[1];

	buf = dst;
	ret = 0;
	c = *fmt;
	while (c != '\0')
	{
		if (c != '%')
		{
			ret += copy_as_is(size, &fmt, &buf);
			c = *++fmt;
			continue ;
		}
		c = *++fmt;
		if (c != '\0' && lut[(u_char) c])
			ret += lut[(u_char) c](&buf, size - (buf - dst), ap);
		else
			fmt--;
		c = *++fmt;
	}
	return ((int)ret);
}

int	ft_vsnprintf(char *str, size_t size, const char *fmt, va_list ap)
{
	int					ret;
	va_list				ap_save;
	static t_snprintf_f	lut[UCHAR_MAX] = {
	['c'] = ft_snprint_c,
	['%'] = ft_snprint_percent,
	['d'] = ft_snprint_d,
	['p'] = ft_snprint_p,
	['i'] = ft_snprint_d,
	['u'] = ft_snprint_u,
	['x'] = ft_snprint_x,
	['X'] = ft_snprint_upperx,
	['s'] = ft_snprint_s,
	};

	va_copy(ap_save, ap);
	ret = ft_vsnprintf_internal(&(char *[2]){(char *)fmt, str},
			size, lut, &ap_save);
	return (ret);
}
