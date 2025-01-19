/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 03:46:18 by abelov            #+#    #+#             */
/*   Updated: 2025/01/17 03:46:18 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/param.h>
#include "libft.h"

size_t	ft_snprint_c(char **buf, size_t size, va_list *ap)
{
	size_t		desired;
	char *const	str = (char [2]){va_arg(*ap, int), '\0'};

	desired = MIN(1 + FT_TERMINATOR, size);
	ft_memcpy(*buf, str, desired * sizeof (char));
	if (*buf && desired)
		(*buf) += desired - 1;
	return (1);
}

size_t	ft_snprint_percent(char **buf, size_t size, va_list *ap)
{
	size_t		desired;
	char *const	str = (char [2]){'%', '\0'};

	desired = MIN(1 + FT_TERMINATOR, size);
	ft_memcpy(*buf, str, desired * sizeof(char));
	if (*buf && desired)
		(*buf) += desired - 1;
	return (1);
	(void )*ap;
}

size_t	ft_snprint_u(char **buf, size_t size, va_list *ap)
{
	size_t	i;
	char	*str;
	size_t	desired;

	str = ft_uitoa((unsigned int) va_arg(*ap, unsigned int));
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
