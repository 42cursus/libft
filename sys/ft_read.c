/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:22:45 by abelov            #+#    #+#             */
/*   Updated: 2025/02/02 22:22:45 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm/unistd.h>
#include <sys/types.h>
#include <errno.h>

ssize_t	ft_read(int fd, void *buf, size_t nbytes)
{
	register ssize_t	res;

	__asm__ volatile (
		"syscall"
		: "=a" (res)
		: "a" (__NR_read), "D" (fd), "S" (buf), "d" (nbytes)
		: "rcx", "r11", "memory");
	if (res < 0)
	{
		errno = (int)-res;
		res = (ssize_t)(-1);
	}
	return (res);
}
