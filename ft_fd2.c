/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:09:21 by abelov            #+#    #+#             */
/*   Updated: 2023/11/18 20:23:38 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
 * https://stackoverflow.com/questions/25848815/
 * #define ENOUGH ((CHAR_BIT * sizeof(int) - 1) / 3 + 2)
 */
#define ENOUGH 12

static size_t	get_int_buf_size(int nb)
{
	size_t		size;
	int const	decimal_radix = 10;

	size = !nb;
	if (nb < 0)
		size++;
	while (nb)
	{
		nb /= decimal_radix;
		size++;
	}
	return (++size);
}

/**
 * Outputs the integer 'n' to the given file descriptor.
 */
void	ft_putnbr_fd(int n, int fd)
{
	char	string[ENOUGH];

	if (fd > SHRT_MAX || fd < 0)
		return ;
	ft_memset(string, 0, ENOUGH);
	ft_itoa_buf(n, string, get_int_buf_size(n));
	ft_putstr_fd(string, fd);
}
