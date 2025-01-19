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

void	*ft_reallocarray(void *ptr, size_t oldnmemb, size_t newnmemb,
							size_t size)
{
	void			*new_ptr;
	const size_t	newsize = newnmemb * size;
	const size_t	oldsize = oldnmemb * size;

	if (!ptr)
	{
		ptr = malloc(newsize);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if ((oldsize / size) != oldsize || ((newsize / size) != newsize))
		return (NULL);
	new_ptr = malloc(newsize);
	if (!new_ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (newsize > oldsize)
		ft_memcpy(new_ptr, ptr, oldsize);
	else
		ft_memcpy(new_ptr, ptr, newsize);
	free(ptr);
	return (new_ptr);
}
