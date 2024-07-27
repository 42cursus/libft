/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:13:01 by abelov            #+#    #+#             */
/*   Updated: 2024/07/27 18:19:20 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

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
	const char	*s;
	const char	*save = little;

	if (big == little || !(*little))
		return ((char *)big);
	while ((len > 0) && *big)
	{
		s = big;
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
