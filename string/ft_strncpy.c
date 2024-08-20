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
 * If there is no terminating null byte in the first n bytes of src, strncpy()
 * produces an unterminated string in dest.
 * `const char*` is a mutable pointer to an immutable character/string.
 * You cannot change the contents of the location(s) this pointer points to.
 */
char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	char *const		save_pointer = dest;
	unsigned int	i;

	i = 0;
	while (*src && (i++ < n))
		*dest++ = *src++;
	while (i++ < n)
		*dest++ = '\0';
	return (save_pointer);
}
