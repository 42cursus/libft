/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:37:56 by abelov            #+#    #+#             */
/*   Updated: 2023/11/18 20:24:23 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_memset() fills memory with a constant byte,
 * returns a pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*d;

	d = s;
	while (n-- != 0)
		*d++ = (unsigned char)c;
	return (s);
}

/**
 * The ft_memcpy() copies n bytes from memory area src to memory area dest.
 * The memory areas must not overlap otherwise use ft_memmove().
 * ISO/IEC 9899:2023 Programming languages - C
 * https://news.ycombinator.com/item?id=36451907
 * https://stackoverflow.com/
 * questions/54964262/implement-memcpy-is-unsigned-char-needed-or-just-char
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *const			save_pointer = dest;
	const unsigned char	*s = src;

	if (!src && !dest)
		return (NULL);
	while (n-- > 0)
		*(unsigned char *)dest++ = *s++;
	return (save_pointer);
}

/**
 *  The  ft_memmove() function copies n bytes from memory area src to
 *  memory area dest.  The memory areas may overlap.
 *  Returns a pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *const			save_pointer = dest;

	if (!src && !dest)
		return (NULL);
	if (src > dest)
		while (n--)
			*(unsigned char *)dest++ = *(unsigned char *)src++;
	else
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	return (save_pointer);
}

/**
 * The ft_memchr() function scans the initial n bytes of the memory area
 * pointed to by s for the first instance of c. Both c and the  bytes  of
 * the memory area pointed to by s are interpreted as unsigned char.
 * Returns a pointer to the matching byte or NULL
 * if the character does not occur in the given memory area.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p = s;

	if (n != 0)
	{
		while (n-- != 0)
			if (*p++ == (unsigned char)c)
				return ((void *)(p - 1));
	}
	return (NULL);
}

/**
 * The ft_memcmp() function compares the first n bytes (each interpreted
 * as unsigned char) of the memory areas s1 and s2.
 * returns an integer less than, equal to, or greater than zero if the first n
 * bytes of s1 is found, respectively, to be less than, to match, or be greater
 * than the first n bytes of s2. For a nonzero return  value,
 * the sign is determined by the sign of the difference between the first pair
 * of bytes (interpreted as unsigned char) that differ in s1 and s2.
 * If n is zero, the return value is zero.
 *
 * Do not use memcmp() to compare security critical data.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n-- > 0)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}
