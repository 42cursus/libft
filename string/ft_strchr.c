/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:37:05 by abelov            #+#    #+#             */
/*   Updated: 2024/06/22 17:37:05 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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
 * The ft_strrchr() function returns a pointer to the last occurrence
 * of the character c in the string s.
 */
char	*ft_strrchr(const char *s, int chr)
{
	const char	*save = s;
	char		c;

	c = (char )chr;
	while (*s)
		s++;
	while ((s != save) && (*s != c))
		s--;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
