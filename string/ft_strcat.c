/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:18:46 by abelov            #+#    #+#             */
/*   Updated: 2024/06/14 18:24:02 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The ft_strcat() function  appends  the src string to the dest string,
 * overwriting the terminating null byte ('\0') at the end of dest,
 * and then adds a terminating null byte. The strings may not overlap,
 * and the dest string must have enough space for the result.
 *
 * Returns a pointer to the resulting string dest.
 */
char	*ft_strcat(char *dest, const char *src)
{
	char *const	save = dest;
	const char	null_byte = '\0';

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = null_byte;
	return (save);
}

/**
 * https://www.joelonsoftware.com/2001/12/11/back-to-basics/
 */
char	*ft_strpcat(char *dest, const char *src)
{
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}
