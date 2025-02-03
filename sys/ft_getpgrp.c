/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpgrp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:04:26 by abelov            #+#    #+#             */
/*   Updated: 2025/02/02 23:04:27 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <asm/unistd.h>
#include <errno.h>

/**
 * The POSIX.1 getpgrp() always returns the PGID of the caller.
 * @return the PGID of the calling process
 */
pid_t	ft_getpgrp(void)
{
	pid_t	res;

	__asm__ volatile (
		"syscall"
		: "=a" (res) :
		"a" (__NR_getpgrp)
		: "rcx", "r11", "memory");
	return (res);
}
