/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setpgrp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:21:12 by abelov            #+#    #+#             */
/*   Updated: 2025/02/02 23:21:13 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm/unistd.h>
#include <errno.h>

/**
 * equivalent to ft_setpgid(0, 0).
 */
int	ft_setpgrp(void)
{
	register int	res;

	__asm__ volatile (
		"syscall"
		: "=a" (res)
		: "a" (__NR_setpgid), "D" (0), "S" (0)
		: "rcx", "r11", "memory");
	if (res < 0)
	{
		errno = (int)-res;
		res = (-1);
	}
	return (res);
}
