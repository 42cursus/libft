# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 02:54:14 by abelov            #+#    #+#              #
#    Updated: 2024/06/14 17:49:43 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES   = ft_exit.c \
			ft_getpgid.c \
			ft_getpgrp.c \
			ft_getpid.c \
			ft_getrandom.c \
			ft_read.c \
			ft_setpgid.c \
			ft_setpgrp.c \
			ft_sigprocmask.c \
			ft_syscall.c

FT_SRCS    += $(FILES:%.c=$(dir $(lastword $(MAKEFILE_LIST)))%.c)
