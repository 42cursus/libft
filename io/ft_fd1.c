/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:09:21 by abelov            #+#    #+#             */
/*   Updated: 2023/11/18 20:23:32 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/**
 * Outputs the character 'c' to the given file descriptor.
 */
void	ft_putchar_fd(char c, int fd)
{
	if (fd > SHRT_MAX || fd < 0)
		return ;
	if (write(fd, &c, 1) == -1)
		return ;
}

/**
 * Outputs the string 's' to the given file descriptor.
 */
void	ft_putstr_fd(const char *const s, int fd)
{
	if (fd > SHRT_MAX || fd < 0 || !s)
		return ;
	if (write(fd, s, ft_strlen(s)) == -1)
		return ;
}

/**
 * Outputs the string 's' to the given file descriptor followed by a newline.
 */
void	ft_putendl_fd(const char *const s, int fd)
{
	if (fd > SHRT_MAX || fd < 0 || !s)
		return ;
	if (write(fd, s, ft_strlen(s)) == -1)
		return ;
	if (write(fd, "\n", 1) == -1)
		return ;
}

/**
 * Outputs at most nbytes from the buffer 's' to the given file descriptor.
 * @param s
 * @param nbytes
 * @param fd
 */
void	ft_putbyte_fd(const char *const s, size_t nbytes, int fd)
{
	if (fd > SHRT_MAX || fd < 0 || !s)
		return ;
	if (write(fd, s, nbytes) == -1)
		return ;
}
