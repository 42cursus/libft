/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setpgid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:10:38 by abelov            #+#    #+#             */
/*   Updated: 2025/02/01 17:10:39 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <asm/unistd.h>
#include <errno.h>

/**
 * @details
 * 	sets  the  PGID  of  the process specified by pid to pgid.
 * @param pid
 *	If pid is zero, then the process ID of the calling process is used.
 * @param pgid
 * 	If pgid is zero, then the PGID of the process specified by pid is made
 * 	the same as its process ID.
 * @return zero on success.
 * 	On error, -1 is returned, and errno is set appropriately:
 * 	EACCES
 * 		An attempt was made to change the process group ID of one of
 * 		the children of the calling process and the child had already
 * 		performed an execve(2).
 * 	EINVAL
 * 		pgid is less than 0.
 * 	EPERM
 * 		An attempt was made to move a process into a process group in a differ-
 * 		ent session, or to change the process group ID of one of the children
 * 		of the calling process and the child was in a different session,
 * 		or to change the process group ID of a session leader.
 * 	ESRCH
 * 		Pid is not the calling process and not a child of the calling process.
 */
int	ft_setpgid(pid_t pid, pid_t pgid)
{
	register int	res;

	__asm__ volatile (
		"syscall"
		: "=a" (res)
		: "a" (__NR_setpgid), "D" (pid), "S" (pgid)
		: "rcx", "r11", "memory");
	if (res < 0)
	{
		errno = (int)-res;
		res = (-1);
	}
	return (res);
}
