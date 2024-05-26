/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:37:43 by abelov            #+#    #+#             */
/*   Updated: 2023/11/02 17:37:47 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strlen() - calculates the length of the string pointed to by s, excluding
 * the terminating null byte ('\0').
 * Returns the number of bytes in the string pointed to by s.
 */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * The ft_strchr() function returns a pointer to the first occurrence of the
 * character c in the string s.
 * It returns a pointer to the matched character or NULL if the character
 * isn't found. The terminating null byte is considered part of the string,
 * so that if c is specified as '\0', the function returns a pointer to the NULL
 * terminator.
 */
char	*ft_strchr(const char *s, int chr)
{
	char	c;

	c = (char )chr;
	while (*s && (*s != c))
		s++;
	if (*s != c)
		return (NULL);
	return ((char *)s);
}

/**
 * The ft_strlcpy() function copies up to size - 1 characters
 * from the NUL-terminated string src to dst, NUL-terminating the result.
 * Returns the total length of the string tried to create (the length of src).
 * Return count does not include NUL character.
 * If retval >= dsize, truncation occurred.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	const char	*save = src;

	if (size > 0)
	{
		while (size-- > 1 && *src)
			*dest++ = *src++;
		*dest = '\0';
	}
	while (*src)
		src++;
	return (src - save);
}

/**
 *  The ft_strlcat() function concatenates strings. It take the full size of
 *  the buffer (not just the length) and guarantees to NUL-terminate the result
 *  (as long as there is at least one byte free in dst).
 *  ft_strlcat() only operate on true “C” strings.  This means that both src
 *  and dst must be NUL-terminated.
 *
 *  Returns the total length of the string tried to create.
 *  That means the initial length of dst plus the length of src.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	const size_t	osize = size;
	char *const		odest = dest;
	size_t			dest_len;

	while (size-- && *dest)
		dest++;
	dest_len = dest - odest;
	if (dest_len >= osize)
		return (osize + ft_strlen(src));
	return (dest_len + ft_strlcpy(dest, src, osize - dest_len));
}
