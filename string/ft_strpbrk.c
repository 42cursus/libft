/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:57:57 by abelov            #+#    #+#             */
/*   Updated: 2024/08/12 17:57:58 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * Find the first occurrence in s1 of a character in s2 (excluding NUL).
 */
char	*ft_strpbrk(const char *s1, const char *s2)
{
	char		c;
	const char	*scan_ptr;

	if (!s1 || !s2)
		return (NULL);
	while (*s1)
	{
		c = *s1++;
		scan_ptr = s2;
		while (*scan_ptr)
		{
			if (*scan_ptr == c)
				return ((char *)(s1 - 1));
			scan_ptr++;
		}
	}
	return (NULL);
}
