/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:26:21 by abelov            #+#    #+#             */
/*   Updated: 2024/05/23 05:52:29 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Compares s1 and s2, returning less than, equal to or greater than zero
 * if s1 is lexicographically less than, equal to or greater than s2.
 *
 * POSIX.1 specifies only that:
 *		  The sign of a nonzero return value shall be determined by
 *		  the sign of the difference between the values of the first
 *		  pair of bytes (both interpreted as type unsigned char)
 *		  that differ in the strings being compared.
 * Note:
 * 		In glibc, as in most other implementations,
 * 		the return value is the arithmetic result of subtracting
 * 		the last compared byte in s2 from the last compared byte in s1.
 * 		(If the two characters are equal, this difference is 0.)
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2++)
		if (*s1++ == 0)
			return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
