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

size_t	ft_print_c(va_list *argp)
{
	ft_putchar_fd(va_arg(*argp, int), STDOUT_FILENO);
	return (1);
}

size_t	ft_print_percent(va_list *argp)
{
	(void )*argp;
	ft_putchar_fd('%', STDOUT_FILENO);
	return (1);
}

size_t	ft_print_u(va_list *argp)
{
	size_t	i;
	char	*str;

	str = ft_uitoa((unsigned int) va_arg(*argp, unsigned int));
	if (!str)
	{
		free(str);
		return (0);
	}
	ft_putstr_fd(str, STDOUT_FILENO);
	i = ft_strlen(str);
	free(str);
	return (i);
}
