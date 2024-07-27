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
