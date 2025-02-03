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
	unsigned long int				res;
	register size_t _a4				asm ("r10");
	register sigset_t *_a3			asm ("rdx");
	register const sigset_t *_a2	asm ("rsi");
	register int _a1				asm ("rdi");

	_a4 = _NSIG / 8;
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
