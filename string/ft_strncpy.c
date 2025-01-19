/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:20:51 by abelov            #+#    #+#             */
/*   Updated: 2023/10/15 18:02:09 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Copy src to dest, truncating or null-padding to always copy n bytes.
 * Return dest.
 * `const char*` is a mutable pointer to an immutable character/string.
 * You cannot change the contents of the location(s) this pointer points to.
 *
 * Warning:
 * 	If there is no null byte among the first n bytes of src, the string placed
 * 	in dest will not be null-terminated.
 */
char	*ft_strncpy(char *dst, const char *src, unsigned int n)
{
	char *const	dest = dst;
	const char	*s = src;

	while (n-- != 0)
	{
		*dst++ = *s;
		if (*s++ == 0)
		{
			while (n-- != 0)
				*dst++ = '\0';
			break ;
		}
	}
	return (dest);
}
