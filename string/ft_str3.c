/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 03:40:56 by abelov            #+#    #+#             */
/*   Updated: 2023/12/31 03:40:58 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates char array and fills it with empty bytes.
 * Returns the new string or NULL if the allocation fails.
 */
char	*ft_empty_string(size_t length)
{
	char			*new;
	unsigned char	*ptr;

	new = (char *)malloc(sizeof(char) * ++length);
	if (!new)
		return (NULL);
	ptr = (unsigned char *)new;
	while (length-- > 0)
		*ptr++ = '\0';
	return (new);
}

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
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	new = ft_empty_string(ft_strlen(s1) + ft_strlen(s2));
	if (!new)
		return (NULL);
	dest = new;
	while (*s1)
		*dest++ = *s1++;
	while (*s2)
		*dest++ = *s2++;
	*dest = '\0';
	return (new);
}

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

/**
 * Applies the function 'f' on each character of the string passed as argument,
 * passing its index as first argument.
 * Each character is passed by address to 'f' to be modified if necessary.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (*s)
		f(i++, s++);
}

/**
 * Applies the function 'f' to each character of the string 's', and passing
 * its index as first argument to create a new string (with malloc(3)) resulting
 * from successive applications of 'f'.
 * Parameters
 * 		s: The string on which to iterate.
 * 		f: The function to apply to each character.
 * Return value:
 * 		The string created from the successive applications of 'f'.
 * 		Returns NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*new;

	if (!s || !f)
		return (NULL);
	i = 0;
	new = ft_strdup((char *)s);
	if (!new)
		return (NULL);
	while (new[i])
	{
		new[i] = f(i, new[i]);
		i++;
	}
	return (new);
}
