/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigprocmask.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:28:45 by abelov            #+#    #+#             */
/*   Updated: 2025/02/03 02:22:10 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <errno.h>
#include <asm/unistd.h>
#include <sys/types.h>

/**
 * sigprocmask() is used to fetch and/or change the signal mask of the calling
 * 	thread. The signal mask is the set of signals whose delivery is currently
 * 	blocked for the caller (see also signal(7) for more details).
 *
 * @param how
 * @param set
 * @param oldset
 * @param setsize
 * @return 0 on success and -1 on error.
 * 	In the event of  an  error, errno is set to indicate the cause.
 */
int	ft_rt_sigprocmask(int how, const sigset_t *set,
						sigset_t *oldset, size_t setsize)
{
	unsigned long int				res;
	register size_t _a4				asm ("r10");
	register sigset_t *_a3			asm ("rdx");
	register const sigset_t *_a2	asm ("rsi");
	register int _a1				asm ("rdi");

	_a4 = setsize;
	_a3 = oldset;
	_a2 = set;
	_a1 = how;
	asm volatile (
		"syscall"
		: "=a" (res)
		: "0" (__NR_rt_sigprocmask), "r" (_a1), "r" (_a2), "r" (_a3), "r" (_a4)
		: "memory", "cc", "r11", "cx");
	if ((long)res < 0)
	{
		errno = (int) -res;
		res = (-1);
	}
	return ((int)res);
}

int	ft_sigprocmask(int how, const sigset_t *set, sigset_t *oldset)
{
	return ((int)ft_rt_sigprocmask(how, set, oldset, _NSIG / 8));
}
