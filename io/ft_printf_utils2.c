/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:12:15 by abelov            #+#    #+#             */
/*   Updated: 2023/12/11 20:12:17 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_print_c(int fd, va_list *ap)
{
	ft_putchar_fd(va_arg(*ap, int), fd);
	return (1);
}

size_t	ft_print_percent(int fd, va_list *ap)
{
	(void )*ap;
	ft_putchar_fd('%', fd);
	return (1);
}

size_t	ft_print_u(int fd, va_list *ap)
{
	size_t	i;
	char	*str;

	str = ft_uitoa((unsigned int) va_arg(*ap, unsigned int));
	if (!str)
	{
		free(str);
		return (0);
	}
	ft_putstr_fd(str, fd);
	i = ft_strlen(str);
	free(str);
	return (i);
}
