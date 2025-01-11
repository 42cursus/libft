# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 00:38:57 by abelov            #+#    #+#              #
#    Updated: 2024/06/14 17:50:07 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES   = ft_fd1.c \
           ft_fd2.c \
           ft_putstr.c \
           ft_putstr_eol.c \
           ft_print_hex.c \
           ft_print_unsigned.c \
           ft_gnl.c \
           ft_getline.c \
           ft_gnl_utils.c

FT_SRCS    += $(FILES:%.c=$(dir $(lastword $(MAKEFILE_LIST)))%.c)
