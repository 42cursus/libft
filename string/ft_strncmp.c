/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:39:04 by abelov            #+#    #+#             */
/*   Updated: 2024/07/02 16:39:05 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

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
