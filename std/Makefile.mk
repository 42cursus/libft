# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 02:54:14 by abelov            #+#    #+#              #
#    Updated: 2023/12/16 02:54:17 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES   = ft_calloc.c \
           ft_atoi.c \
           ft_itoa.c \
           ft_strtol.c \
           ft_strtoul.c \
           ft_atoi_base.c

SRCS    += $(patsubst %.c,std/%.c,$(FILES))
