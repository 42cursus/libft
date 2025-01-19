/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:37:12 by abelov            #+#    #+#             */
/*   Updated: 2023/11/18 20:28:59 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <errno.h>

char	*ft_strdup(const char *const src)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!new)
	{
		errno = ENOMEM;
		return (NULL);
	}
	*new = '\0';
	return (ft_strcpy(new, src));
}
