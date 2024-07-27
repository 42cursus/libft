/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:18:03 by abelov            #+#    #+#             */
/*   Updated: 2024/07/27 18:18:04 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
