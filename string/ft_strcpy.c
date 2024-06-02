/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:09:12 by abelov            #+#    #+#             */
/*   Updated: 2023/10/12 19:51:11 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Function  copies the string pointed to by src, including the terminating
 * null byte ('\0'), to the buffer  pointed  to  by  dest.
 * The strcpy() function returns a pointer to the destination string dest.
 * The strings  may  not overlap, and the destination string dest must be
 * large enough to receive the copy. If the destination string of a strcpy()
 * is not large enough, then anything might happen.
 * `char *const` is an immutable pointer (it cannot point to any other location)
 * but the contents of location at which it points are mutable.
 * stackoverflow.com/questions/9834067/difference-between-char-and-const-char
 */
char	*ft_strcpy(char *dest, char *src)
{
	char *const	save = dest;
	const char	null_byte = '\0';

	while (*src)
		*dest++ = *src++;
	*dest = null_byte;
	return (save);
}
