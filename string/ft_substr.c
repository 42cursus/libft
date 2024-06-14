/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:43:41 by abelov            #+#    #+#             */
/*   Updated: 2024/06/14 22:43:41 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/**
 * Description:
 * 		Allocates (with malloc(3)) and returns a substring from the string 's'.
 * Parameters:
 * 		s: The string from which to create the substring.
 * 		start: The start index of the substring in the string `s`.
 * 		len: The maximum length of the substring.
 * Return value:
 * 		The substring.
 * 		NULL if the allocation fails.
 * The substring begins at index 'start' and is of maximum size 'len'.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	lenstr;
	size_t	remainder;

	if (!s)
		return (NULL);
	lenstr = ft_strlen(s);
	if (!lenstr || (start > lenstr) || !len)
		return ((char *)ft_calloc(1, sizeof(char)));
	remainder = lenstr - start;
	if (len < remainder)
		remainder = len;
	new = ((char *)ft_calloc(remainder + 1, sizeof(char)));
	if (!new)
		return (NULL);
	ft_strlcat(new, (s + start), remainder + 1);
	return (new);
}
