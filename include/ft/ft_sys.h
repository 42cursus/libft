/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sys.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 02:04:50 by abelov            #+#    #+#             */
/*   Updated: 2025/01/20 02:04:51 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SYS_H
# define FT_SYS_H

# include <sys/types.h>

void	ft_exit(int exit_code);
pid_t	ft_getpgid(pid_t pid);
pid_t	ft_getpgrp(void);
pid_t	ft_getpid(void);
pid_t	ft_getppid(void);
ssize_t	ft_getrandom(void *buffer, size_t length, unsigned int flags);
ssize_t	ft_read(int fd, void *buf, size_t nbytes);
int		ft_setpgid(pid_t pid, pid_t pgid);
int		ft_setpgrp(void);
int		ft_sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
int		ft_syscall3(int num, int arg1, long arg2, int arg3);
long	ft_syscall_x64(long num, ...);
int		ft_rt_sigprocmask(int how, const sigset_t *set,
			sigset_t *oldset, size_t setsize);
#endif //FT_SYS_H
