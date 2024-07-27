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

/**
 * The ft_strndup() function is similar to ft_strdup, but copies at most nb
 * bytes. If s is longer than nb, only nb bytes are copied,
 * and a terminating null byte ('\0') is added.
 */
char	*ft_strndup(const char *src, unsigned int nb)
{
	char	*dst;

	if (!src)
		return (NULL);
	dst = ft_strnew(ft_strlen(src));
	if (!dst)
		return (NULL);
	return (ft_strncpy(dst, src, nb));
}
