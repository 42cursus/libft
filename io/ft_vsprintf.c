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
	int		result;
	va_list	ap_save;

	va_copy(ap_save, ap);
	result = ft_vsnprintf(NULL, 0, format, ap);
	if (result < 0)
		return (FT_ERROR);
	result = ft_vsnprintf(str, (size_t)result + 1, format, ap);
	va_end(ap_save);
	return (result);
}

ssize_t	copy_as_is(size_t size, const char **fmt, char **buf)
{
	const char *const	ptr = ft_strchrnul((*fmt), '%');
	const size_t		i = (size_t)(ptr - *fmt);
	const size_t		desired = MIN(i + FT_TERMINATOR, size);

	ft_memcpy((*buf), *fmt, desired * sizeof(char));
	if (*buf)
		(*buf) += desired - 1 * (desired > 1);
	(*fmt) = (ptr - 1);
	return ((ssize_t)i);
}

static inline __attribute__((always_inline))
t_printf_var	handle_spec(va_list *const ap, t_printf_var v, ssize_t *ret)
{
	char	cc;

	cc = v.fmt[1];
	if (cc == '\0')
	{
		if (v.rem > 0 && v.seek)
			v.error_flag = FT_ERROR;
		(*ret)++;
	}
	else
	{
		if (v.lut[(u_char)cc] != NULL)
			(*ret) += (ssize_t) v.lut[(u_char)cc](&v.seek, v.rem, ap);
		else
		{
			if (v.seek && v.rem > 0)
				*v.seek++ = '%';
			if (v.seek && v.rem > 1)
				*v.seek++ = cc;
			(*ret) += 2;
		}
		v.fmt++;
	}
	return (v);
}

int	ft_vsnprintf_internal(t_printf_var v, size_t size, va_list *ap)
{
	register char	c;
	ssize_t			ret;

	ret = 0;
	v.seek = v.buf;
	c = *v.fmt;
	while (c != '\0' && v.error_flag != FT_ERROR)
	{
		v.rem = size - (v.seek - v.buf);
		if (c == '%')
			v = handle_spec(ap, v, &ret);
		else
			ret += copy_as_is(v.rem, &v.fmt, &v.seek);
		v.fmt++;
		c = *v.fmt;
	}
	if (v.error_flag)
		ret = FT_ERROR;
	return ((int)ret);
}

int	ft_vsnprintf(char *dst, size_t size, const char *fmt, va_list ap)
{
	int					ret;
	size_t				mini_size;
	va_list				ap_save;
	t_printf_var		var;
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
	['w'] = ft_snprint_w,
	};

	mini_size = size - (size != 0) * 1;
	va_copy(ap_save, ap);
	var = (t_printf_var){.buf = dst, .fmt = fmt, .lut = lut};
	ret = ft_vsnprintf_internal(var, mini_size, &ap_save);
	va_end(ap_save);
	if (size && ret >= 0)
		dst[MIN(mini_size, (u_int)ret)] = '\0';
	return (ret);
}
