/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:46:04 by abelov            #+#    #+#             */
/*   Updated: 2025/01/20 01:46:04 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdarg.h>

/**
 * from man SYSCALL(2)
 * The first table lists the instruction used to transition to kernel mode
 * Arch/ABI    Instruction           System  Ret  Ret  Error
 *                                   call #  val  val2
 * ──────────────────────────────────────────────────────────
 * i386        int $0x80             eax     eax  edx  -
 * x86-64      syscall               rax     rax  rdx  -
 *
 * The second table registers used to pass the system call arguments.
 * Arch/ABI      arg1  arg2  arg3  arg4  arg5  arg6  arg7
 * ───────────────────────────────────────────────────────
 * i386          ebx   ecx   edx   esi   edi   ebp   -
 * x86-64        rdi   rsi   rdx   r10   r8    r9    -
 */
int	ft_syscall3(int num, int arg1, long arg2, int arg3)
{
	int	res;

	__asm__ volatile (
		"syscall"
		: "=a" (res)
		: "a" (num), "D" (arg1), "S" (arg2), "d" (arg3)
		: "memory", "cc");
	if (-125 <= res && res < 0)
	{
		errno = -res;
		res = -1;
	}
	return (res);
}

/**
 * syscall arguments are typically passed in registers and interpreted
 * as integers or pointers, which are effectively the same size.
 *
 * Use the syscall instruction (direct syscall implementation).
 * Get up to 6 arguments (Linux syscall ABI typically supports up to 6 args)
 */
long	ft_syscall_x64(long num, ...)
{
	va_list				args;
	long				result;
	register long r10	__asm__("r10");
	register long r8	__asm__("r8");
	register long r9	__asm__("r9");

	va_start(args, num);
	r10 = va_arg(args, long);
	r8 = va_arg(args, long);
	r9 = va_arg(args, long);
	va_end(args);
	asm volatile (
		"syscall"
		: "=a" (result)
		: "a" (num), "D" (va_arg(args, long)), "S" (va_arg(args, long)),
		"d"(va_arg(args, long)), "r"(r10), "r"(r8), "r"(r9)
		: "rcx", "r11", "memory"
	);
	return (result);
}
