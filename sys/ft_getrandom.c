/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getrandom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 02:16:18 by abelov            #+#    #+#             */
/*   Updated: 2025/01/20 02:16:19 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <asm/unistd.h>
#include <unistd.h>
#include "ft/ft_sys.h"

static __inline long	ft_syscall(long n, long arg1, long arg2, long arg3)
{
	unsigned long	ret;

	__asm__ volatile (
		"syscall"
		: "=a" (ret)
		: "a" (n), "D" (arg1), "S" (arg2), "d" (arg3)
		: "rcx", "r11", "memory");
	return ((long)ret);
}

/**
 * Write up to LENGTH bytes of randomness starting at BUFFER.
 * Return the number of bytes written, or -1 on error.
 */
ssize_t	ft_getrandom(void *buffer, size_t length, unsigned int flags)
{
	return (ft_syscall(__NR_getrandom, (long) buffer, length, flags));
}
