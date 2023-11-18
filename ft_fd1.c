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
	write(fd, &c, 1);
}

/**
 * Outputs the string 's' to the given file descriptor.
 */
void	ft_putstr_fd(char *s, int fd)
{
	if (fd > SHRT_MAX || fd < 0 || !s)
		return ;
	write(fd, s, ft_strlen(s));
}

/**
 * Outputs the string 's' to the given file descriptor followed by a newline.
 */
void	ft_putendl_fd(char *s, int fd)
{
	if (fd > SHRT_MAX || fd < 0 || !s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
