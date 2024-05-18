/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:44:26 by abelov            #+#    #+#             */
/*   Updated: 2023/11/18 20:23:18 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

/**
 * The ft_calloc() function allocates memory for an array of nmemb elementqs of
 * size bytes each and returns a pointer to the allocated memory.
 * The memory is set to zero.  If nmemb or size is 0, then ft_calloc() returns
 * either NULL, or  a unique pointer value that can later be passed to free().
 * If the multiplication of nmemb and size would result in integer overflow,
 * then ft_calloc() returns an error.
 *
 * The return is a pointer to the allocated memory, which is suitably aligned
 * for any built-in  type. On error returns NULL.
 * NULL may also be returned by a successful call to ft_calloc() with nmemb or
 * size equal to zero.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	bytes;

	if ((nmemb <= 0) || (size <= 0))
	{
		nmemb = 1;
		size = 1;
	}
	bytes = nmemb * size;
	if ((bytes / size) != nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}
