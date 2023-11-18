/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:09:21 by abelov            #+#    #+#             */
/*   Updated: 2023/11/10 18:09:23 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
 * https://stackoverflow.com/questions/25848815/
 * #define ENOUGH ((CHAR_BIT * sizeof(int) - 1) / 3 + 2)
 */
#define ENOUGH 12

static void	ft_revstr(char *tab, size_t size)
{
	char	*head;
	char	*tail;
	char	tmp;

	head = tab;
	tail = tab + size - 1;
	while (head <= tail)
	{
		tmp = *head;
		*head++ = *tail;
		*tail-- = tmp;
	}
}

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

static void	ft_itoa_buf(int nb, char *buf, size_t length)
{
	unsigned int		r;
	unsigned int const	decimal_radix = 10;
	int const			mask = nb >> (sizeof(int) * CHAR_BIT - 1);

	r = (nb + mask) ^ mask;
	while (r >= decimal_radix)
	{
		ft_strlcat(buf, (char [2]){(r % decimal_radix) + '0', '\0'}, length);
		r /= decimal_radix;
	}
	ft_strlcat(buf, (char [2]){(r + '0'), '\0'}, length);
	if (nb < 0)
		ft_strlcat(buf, (char [2]){'-', '\0'}, length);
	ft_revstr(buf, --length);
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