/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:48:14 by abelov            #+#    #+#             */
/*   Updated: 2023/10/17 21:01:38 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "ft_string.h"

/**
 * The  ft_strncat() function  appends at most n bytes from src string to
 * the dest string, overwriting the terminating null byte ('\0') at the end
 * of dest, and then adds a terminating null byte. The strings may not overlap,
 * and the dest string must have enough space for the result.
 * The src does not need to be null-terminated if it contains n or more bytes.
 * The resulting string in dest is always null-terminated.
 * If  src  contains  n or more bytes, strncat() writes n+1 bytes to dest
 * (n from src plus the terminating null byte).
 * Therefore, the size of dest must be at least strlen(dest)+n+1.
 */
char	*ft_strncat(char *d, const char *src, u_int n)
{
	char *const	dst = d;
	const char	*s = src;

	if (n != 0)
	{
		while (*d != 0)
			d++;
		while (n--)
		{
			*d = *s++;
			if (*d == '\0')
				break ;
			d++;
		}
		*d = 0;
	}
	return (dst);
}

/**
 * https://www.joelonsoftware.com/2001/12/11/back-to-basics/
 */
char	*ft_strnpcat(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (*dest)
		dest++;
	while (*src && (i++ < n))
		*dest++ = *src++;
	while (i++ < n)
		*dest++ = '\0';
	return (--dest);
}
