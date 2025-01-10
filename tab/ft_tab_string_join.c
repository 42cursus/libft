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

#include "ft/ft_string.h"

t_uint	ft_tab_get_size(void const **tab);

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
char	*ft_tab_str_join(char const **strs, size_t nmemb, const char *sep)
{
	char	*new;
	char	*p;
	size_t	i;

	if (nmemb <= 0)
		return (ft_strnew(0));
	i = ft_strlen_all(strs, nmemb) + (ft_strlen(sep) * (nmemb - 1));
	new = ft_strnew(i);
	i = -1;
	if (++i < nmemb)
		p = ft_strpcat(new, strs[i]);
	while (++i < nmemb)
		p = ft_strpcat(ft_strpcat(p, sep), strs[i]);
	return (new);
}

char	*ft_tab_string_join(char const **str_tab)
{
	size_t	size;

	size = ft_tab_get_size((const void **) str_tab);
	return (ft_tab_str_join(str_tab, size, " "));
}
