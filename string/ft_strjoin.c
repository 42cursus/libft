/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:03:15 by abelov            #+#    #+#             */
/*   Updated: 2024/06/14 18:23:06 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include "ft_string.h"
#include <errno.h>

/**
 * Allocates (with malloc(3)) and returns a new string, which is the result
 * of the concatenation of 's1' and 's2'.
 * Parameters
 * 		s1: The prefix string.
 * 		s2: The suffix string.
 * Return value:
 * 		The new string or NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
	{
		errno = ENOMEM;
		return (NULL);
	}
	*new = '\0';
	ft_strpcat(ft_strpcat(new, s1), s2);
	return (new);
}
