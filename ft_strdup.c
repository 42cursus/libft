/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:37:12 by abelov            #+#    #+#             */
/*   Updated: 2023/11/18 20:28:59 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_strcpy(char *dest, char *src)
{
	char *const	save = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (save);
}

char	*ft_strdup(char *src)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!new)
		return (NULL);
	return (ft_strcpy(new, src));
}
