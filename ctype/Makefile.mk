# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 02:54:03 by abelov            #+#    #+#              #
#    Updated: 2023/12/16 02:54:06 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES   = ft_isalnum.c \
			ft_isctype.c \
			ft_isctype2.c

FT_SRCS    += $(FILES:%.c=$(dir $(lastword $(MAKEFILE_LIST)))%.c)
