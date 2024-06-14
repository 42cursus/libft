/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_string_join.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:31:08 by abelov            #+#    #+#             */
/*   Updated: 2024/06/14 18:31:09 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_uint	ft_get_tab_size(void const **tab);

static inline size_t	ft_strlen_all(char const **str_tab, size_t size)
{
	size_t	i;
	size_t	counter;

	i = -1;
	counter = 0;
	while (++i < size)
		counter += ft_strlen(*str_tab++);
	return (counter);
}

/**
 * Concatenates all the strings pointed by strs separated by sep.
 * size is the number of strings in strs.
 * if size is 0, returns an empty string that you can free().
 */
char	*ft_strjoin2(size_t size, char const **strs, char *sep)
{
	char	*new;
	size_t	i;

	if (size <= 0)
		return (ft_empty_string(0));
	i = ft_strlen_all(strs, size) + (ft_strlen(sep) * (size - 1));
	new = ft_empty_string(i);
	i = 0;
	while (i < size - 1)
		ft_strcat(ft_strcat(new, strs[i++]), sep);
	ft_strcat(new, strs[i]);
	return (new);
}

char	*ft_tab_string_join(char const **str_tab)
{
	size_t	size;

	size = ft_get_tab_size((const void **) str_tab);
	return (ft_strjoin2(size, str_tab, " "));
}
