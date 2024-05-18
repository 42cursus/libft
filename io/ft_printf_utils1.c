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

size_t	ft_print_p(va_list *argp)
{
	size_t		i;
	char		*str;
	const void	*ptr = va_arg(*argp, void *);

	str = ft_print_pointer((unsigned long long int) ptr);
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

size_t	ft_print_d(va_list *argp)
{
	size_t	i;
	char	*str;

	str = ft_itoa(va_arg(*argp, int));
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

size_t	ft_print_s(va_list *argp)
{
	size_t	i;
	char	*str;

	str = va_arg(*argp, char *);
	if (!str)
	{
		str = "(null)";
		ft_putstr_fd(str, STDOUT_FILENO);
		return (ft_strlen(str));
	}
	ft_putstr_fd(str, STDOUT_FILENO);
	i = ft_strlen(str);
	return (i);
}

size_t	ft_print_upperx(va_list *argp)
{
	size_t		i;
	char		*str;
	const char	*base = "0123456789ABCDEF";

	str = ft_uitoa_base(va_arg(*argp, unsigned long), base);
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

size_t	ft_print_x(va_list *argp)
{
	size_t		i;
	char		*str;
	const char	*base = "0123456789abcdef";

	str = ft_uitoa_base(va_arg(*argp, unsigned long), base);
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
