/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:43:51 by abelov            #+#    #+#             */
/*   Updated: 2025/01/20 01:43:52 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <asm/unistd.h>

/**
 * @return the process ID (PID) of the calling process.
 * This function is always successful.
 */
pid_t	ft_getpid(void)
{
	register int	res;

	__asm__ volatile (
		"syscall"
		: "=a" (res) :
		"a" (__NR_getpid)
		: "rcx", "r11", "memory");
	return (res);
}
