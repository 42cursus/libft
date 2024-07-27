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

FILES   = ft_atoi.c \
           ft_atoi_base.c \
           ft_bsearch.c \
           ft_bsort.c \
           ft_calloc.c \
           ft_itoa.c \
           ft_lsearch.c \
           ft_nblen.c \
           ft_qsort.c \
           ft_strtol.c \

SRCS    += $(FILES:%.c=$(dir $(lastword $(MAKEFILE_LIST)))%.c)
