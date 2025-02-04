/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getppid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:53:34 by abelov            #+#    #+#             */
/*   Updated: 2025/02/03 23:53:34 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <asm/unistd.h>

/**
 * @return the process ID of the parent of the calling process.
 * 	This will be either the ID of the process that created this process
 * 	using fork(), or, if that process has already terminated, the ID
 * 	of the process to which this process has been reparented.
 * This function is always successful.
 */
pid_t	ft_getppid(void)
{
	register int	res;

	__asm__ volatile (
		"syscall"
		: "=a" (res) :
		"a" (__NR_getppid)
		: "rcx", "r11", "memory");
	return (res);
}
