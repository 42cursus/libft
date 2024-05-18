/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:17:15 by abelov            #+#    #+#             */
/*   Updated: 2023/12/07 20:17:17 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_hex_buf_size(unsigned long long int nb)
{
	ulong		size;
	int const	hexadecimal_radix = 16;

	size = !nb;
	while (nb)
	{
		nb /= hexadecimal_radix;
		size++;
	}
	return (++size);
}

char	*ft_uitoa_base(unsigned int nb, const char *base)
{
	char				*buf;
	size_t				buf_size;

	buf_size = get_hex_buf_size(nb);
	buf = (char *)malloc(sizeof(char) * buf_size);
	if (!buf)
		return (NULL);
	ft_bzero(buf, buf_size);
	return (ft_ultoa_buf_base(nb, buf, buf_size, base));
}

char	*ft_print_pointer(unsigned long long nb)
{
	char				*buf;
	unsigned long long	buf_size;

	buf_size = get_hex_buf_size(nb);
	if (nb == 0)
		buf_size = 4;
	buf = (char *)malloc(sizeof(char) * buf_size + 2);
	if (!buf)
		return (NULL);
	buf[buf_size + 1] = '\0';
	if (nb == 0 && ft_memcpy(buf, "(nil)", buf_size + 1))
		return (buf);
	ft_memset(buf, '0', buf_size);
	buf[1] = 'x';
	ft_ultoa_buf_base(nb, buf + 2, buf_size, "0123456789abcdef");
	return (buf);
}
