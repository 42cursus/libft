/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:37:43 by abelov            #+#    #+#             */
/*   Updated: 2024/07/27 18:03:16 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strlen() - calculates the length of the string pointed to by s, excluding
 * the terminating null byte ('\0').
 * Returns the number of bytes in the string pointed to by s.
 */
size_t	ft_strnlen(const char *s, size_t maxlen)
{
	const char	*found = ft_memchr(s, '\0', maxlen);
	size_t		retval;

	retval = maxlen;
	if (found)
		retval = (size_t)(found - s);
	return (retval);
}

/**
 * ft_strlen() - calculates the length of the string pointed to by s, excluding
 * the terminating null byte ('\0').
 * Returns the number of bytes in the string pointed to by s.
 */
size_t	ft_strlen(const char *str)
{
	const char *const	optr = str;

	while (*str)
		str++;
	return (str - optr);
}
