/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 03:14:49 by abelov            #+#    #+#             */
/*   Updated: 2023/12/31 03:14:51 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/**
 * The ft_strspn() function calculates the length (in bytes) of the initial
 * segment of s which consists entirely of bytes in accept.
 */
size_t	ft_strspn(const char *s, const char *accept)
{
	const char	*optr = s;

	while (*s)
	{
		if (!ft_strchr(accept, *s))
			break ;
		s++;
	}
	return (s - optr);
}

size_t	ft_strcspn_reject(const char *s, const char *reject)
{
	const char	*ptr;
	const char	*rjct;
	size_t		count;

	ptr = s - 1;
	count = 0;
	while (*(++ptr) != '\0')
	{
		rjct = reject;
		while (*rjct != '\0')
		{
			if (*ptr == *rjct)
			{
				count++;
				break ;
			}
			rjct++;
		}
		if (*rjct == '\0')
			break ;
	}
	return (count);
}

/**
 * The ft_strcspn() function calculates the length of the initial segment of s
 * which consists entirely of bytes not in reject.
 */
size_t	ft_strcspn(const char *s, const char *reject)
{
	const char *const	save = s;

	while (*s)
	{
		if (ft_strchr(reject, *s) != NULL)
			break ;
		s++;
	}
	return (s - save);
}
