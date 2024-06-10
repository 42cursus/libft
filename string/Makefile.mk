# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.inc                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 00:38:57 by abelov            #+#    #+#              #
#    Updated: 2023/12/16 00:39:02 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# string sources
FILES	= ft_bsdstr.c \
			ft_bzero.c \
			ft_mem.c \
			ft_split.c \
			ft_str1.c \
			ft_str2.c \
			ft_str3.c \
			ft_strdup.c \
			ft_strspn.c \
			ft_strcpy.c \
			ft_strstr.c \
			ft_strcmp.c \
			ft_strncpy.c \
			ft_strtok.c

SRCS    += $(FILES:%.c=$(dir $(lastword $(MAKEFILE_LIST)))%.c)
