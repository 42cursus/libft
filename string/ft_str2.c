/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:10:54 by abelov            #+#    #+#             */
/*   Updated: 2023/12/18 07:10:55 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_empty_string(size_t length)
{
	char			*new;
	unsigned char	*ptr;

	new = (char *)malloc(sizeof(char) * length + 1);
	if (!new)
		return (NULL);
	ptr = (unsigned char *)new;
	while (--length > 0)
		*ptr++ = '\0';
	return (new);
}
