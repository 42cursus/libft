/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 02:43:15 by abelov            #+#    #+#             */
/*   Updated: 2023/12/31 02:43:17 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *
 * The  ft_strtok()  function  breaks a string into a sequence of zero or more
 * nonempty tokens.  On the first call to ft_strtok(), the string to be parsed
 * should be specified in str. In each subsequent call that  should  parse  the
 * same string, str must be NULL.
 *
 * The delim argument specifies a set of bytes that delimit the tokens in the
 * parsed string.  The caller may specify different strings in delim
 * in successive calls that parse the same string.
 *
 * Each call to ft_strtok() returns a pointer to a null-terminated string
 * containing the next token. This string does not include the delimiting byte.
 * If no more tokens are found, ft_strtok() returns NULL.
 */
char	*ft_strtok(char *str, const char *delim)
{
	static char	*last;

	return (ft_strtok_r(str, delim, &last));
}

/**
 * The strtok_r() function is a reentrant version of strtok().
 * The saveptr argument is a pointer to a char * variable that is used
 * internally by ft_strtok_r() in order to maintain context between successive
 * calls that parse the same string.
 *
 * On the first call to ft_strtok_r(), str should point to the string to be
 * parsed, and the value of *saveptr is  ignored.
 * In subsequent calls, str should be NULL, and saveptr (and the buffer
 * that it points to) should be unchanged since the previous call.
 */
char	*ft_strtok_r(char *str, const char *delim, char **saveptr)
{
	char	*token;

	if (!str)
	{
		str = *saveptr;
		if (!str)
			return (NULL);
	}
	str += ft_strspn(str, delim);
	if (*str == '\0')
	{
		*saveptr = NULL;
		return (NULL);
	}
	token = str;
	str += ft_strcspn(str, delim);
	if (*str == '\0')
		*saveptr = NULL;
	else
	{
		*str++ = '\0';
		*saveptr = str;
	}
	return (token);
}
