/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:21:01 by abelov            #+#    #+#             */
/*   Updated: 2023/12/15 15:21:04 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * The strstr() function finds the first occurrence of the substring needle
 * in the string haystack. The terminating null bytes ('\0') are not compared.
 * Returns a pointer to the beginning of the located substring, or NULL
 * if the substring is not found.
 */
char	*ft_strstr(char *str, char *to_find)
{
	char *const	save = to_find;
	char		*s;

	if (!ft_strlen(to_find))
		return (str);
	while (*str)
	{
		s = str;
		to_find = save;
		while (*to_find == *s++)
			if (!*to_find++)
				return (str);
		str++;
	}
	return (NULL);
}

size_t	ft_strstr_fixed(char *haystack, char *words[])
{
	char		*s;
	char		*needle;
	size_t		i;

	needle = NULL;
	if (!haystack || !*haystack)
		return (0);
	i = -1;
	while (++i < 11)
	{
		s = haystack;
		needle = words[i];
		while (*needle++ == *s++)
			if (!*needle)
				return (i + 1);
	}
	return (0);
}
