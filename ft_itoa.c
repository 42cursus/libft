/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:29:05 by abelov            #+#    #+#             */
/*   Updated: 2023/11/10 18:29:07 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

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
 * https://stackoverflow.com/questions
 * /25848815/why-enough-is-enough-storing-an-int-in-a-char-array
 * Allocates (with malloc(3)) and returns a string representing the integer
 * received as an argument.
 *
 * Returns the string representing the integer. NULL if the allocation fails.
 */
char	*ft_itoa(int nb)
{
	char				*buf;
	size_t				buf_size;

	buf_size = get_int_buf_size(nb);
	buf = (char *)malloc(sizeof(char) * buf_size);
	if (!buf)
		return (NULL);
	ft_bzero(buf, buf_size);
	ft_itoa_buf(nb, buf, buf_size);
	return (buf);
}
