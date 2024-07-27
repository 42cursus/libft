/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:37:55 by abelov            #+#    #+#             */
/*   Updated: 2024/07/02 16:37:55 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/**
 * Allocates (with malloc(3)) and returns a copy of 's1' with the characters
 * specified in 'set' removed from the beginning and the end of the string.
 * Parameters
 * 		s1: The string to be trimmed.
 * 		set: The reference set of characters to trim.
 * Return value:
 * 		The new string or NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	start;
	size_t	stop;
	size_t	lenstr;

	if (!s1)
		return (NULL);
	lenstr = ft_strlen(s1);
	if (lenstr <= 0)
		return ((char *)ft_calloc(1, sizeof(char)));
	start = 0;
	if (ft_strlen(set) <= 0)
		return (ft_strdup((char *)s1));
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	stop = lenstr - 1;
	while (ft_strchr(set, s1[stop]) && stop)
		stop--;
	if (stop < start)
		return ((char *)ft_calloc(1, sizeof(char)));
	new = ft_substr(s1, start, stop - start + 1);
	return (new);
}
