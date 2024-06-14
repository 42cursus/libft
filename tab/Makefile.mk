# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 00:38:57 by abelov            #+#    #+#              #
#    Updated: 2024/06/14 17:49:32 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES   = ft_get_tab_size.c \
			ft_tab_any.c \
			ft_tab_count_if.c \
			ft_tab_foreach.c \
			ft_tab_is_sort.c \
			ft_tab_map.c \
			ft_init_int_tab.c \
			ft_copy_int_tab.c \
			ft_sort_int_tab.c \
			ft_sort_string_tab.c \
			ft_sort_string_tab_fun.c

SRCS    += $(FILES:%.c=$(dir $(lastword $(MAKEFILE_LIST)))%.c)
