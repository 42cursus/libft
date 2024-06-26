/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:13:01 by abelov            #+#    #+#             */
/*   Updated: 2023/11/04 14:13:03 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_strncmp() returns an integer indicating the result of the comparison
 * of the first (at most) n bytes of s1 and s2 as follows:
 *     • 0, if the s1 and s2 are equal;
 *     • a negative value if s1 is less than s2;
 *     • a positive value if s1 is greater than s2.
 * The return value is the arithmetic result of subtracting the last compared
 * byte in s2 from the last compared byte in s1. (If the two characters are
 * equal, this difference is 0.).
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	result;

	result = 0;
	while (n-- > 0)
	{
		if (*s1 != *s2)
		{
			result = *(unsigned char *)s1 - *(unsigned char *)s2;
			break ;
		}
		if (*s1++ == '\0')
			break ;
		s2++;
	}
	return (result);
}

/**
 * The ft_strnstr() function locates the first occurrence of the null-terminated
 * string little in the string big, where not more than len characters are
 * searched. Characters that appear after a '\0' character are not searched.
 * If little is an empty string, big is returned; if little occurs nowhere in
 * big, NULL is returned; otherwise a pointer to the first character of
 * the first occurrence of little is returned.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	char		*s;
	const char	*save = little;

	i = 0;
	s = (char *)big;
	if (big == little || !(*little))
		return (s);
	while ((len > 0) && *big)
	{
		s = (char *)big;
		little = save;
		i = 0;
		while ((*little++ == *s++) && (len != i++))
			if (*little == '\0')
				return ((char *)big);
		len--;
		big++;
	}
	return (NULL);
}
