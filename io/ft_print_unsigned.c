/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:35:31 by abelov            #+#    #+#             */
/*   Updated: 2023/12/07 12:35:38 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_uint_buf_size(unsigned int nb)
{
	size_t		size;
	int const	decimal_radix = 10;

	size = !nb;
	while (nb)
	{
		nb /= decimal_radix;
		size++;
	}
	return (++size);
}

char	*ft_ultoa_buf_base(unsigned long abs, char *buf, size_t length,
						const char *base)
{
	char				*ptr;
	char				c;
	unsigned int const	radix = ft_strlen(base);

	ptr = buf + length - 1;
	*ptr-- = '\0';
	while (abs >= radix)
	{
		c = base[(abs % radix)];
		*ptr-- = c;
		abs /= radix;
	}
	*ptr = base[abs];
	return (buf);
}

char	*ft_uitoa(unsigned int nb)
{
	char				*buf;
	size_t				buf_size;
	const char			*base = "0123456789";

	buf_size = get_uint_buf_size(nb);
	buf = (char *)malloc(sizeof(char) * buf_size);
	if (!buf)
		return (NULL);
	ft_bzero(buf, buf_size);
	return (ft_ultoa_buf_base(nb, buf, buf_size, base));
}
