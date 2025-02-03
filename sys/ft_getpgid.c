/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpgid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:52:54 by abelov            #+#    #+#             */
/*   Updated: 2025/02/02 22:52:54 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <asm/unistd.h>
#include <errno.h>

/**
 * @details
 * 	ft_setpgid() sets the PGID of the process specified by pid to pgid.
 * @param pid
 * 	If pid is zero, then the process ID of the calling process is used.
 * 	If pgid is zero, then the PGID of the process specified by pid is made
 * 	the same as its process ID.
 * @return a process group on success.
 * 	On error, -1 is returned, and errno is set appropriately:
 * 	ESRCH
 * 		Pid does not match any process.
 */
pid_t	ft_getpgid(pid_t pid)
{
	register pid_t	res;

	__asm__ volatile (
		"syscall"
		: "=a" (res)
		: "a" (__NR_getpgid), "D" (pid)
		: "rcx", "r11", "memory");
	if (res < 0)
	{
		errno = (int)-res;
		res = (-1);
	}
	return (res);
}
