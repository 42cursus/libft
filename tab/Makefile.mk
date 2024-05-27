# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 00:38:57 by abelov            #+#    #+#              #
#    Updated: 2024/05/21 05:22:14 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES   = ft_get_tab_size.c \
			ft_tab_any.c \
			ft_tab_count_if.c \
			ft_tab_foreach.c \
			ft_tab_is_sort.c \
			ft_tab_map.c \
			ft_sort_string_tab.c \
			ft_sort_string_tab_fun.c

SRCS    += $(patsubst %.c,tab/%.c,$(FILES))
