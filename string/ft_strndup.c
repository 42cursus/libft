/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:42:23 by abelov            #+#    #+#             */
/*   Updated: 2024/07/02 17:42:24 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

/**
 * The ft_strndup() function is similar to ft_strdup, but copies at most nb
 * bytes. If s is longer than nb, only nb bytes are copied,
 * and a terminating null byte ('\0') is added.
 *
 * ERRORS
 * 		ENOMEM Insufficient memory available to allocate duplicate string.
 */
char	*ft_strndup(const char *src, unsigned int nb)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * (nb + 1));
	if (!new)
	{
		errno = ENOMEM;
		return (NULL);
	}
	new[nb] = '\0';
	ft_strncpy(new, src, nb);
	return (new);
}
