# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 02:54:03 by abelov            #+#    #+#              #
#    Updated: 2024/06/14 17:49:59 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES   = ft_list_at.c \
            ft_list_clear.c \
            ft_list_concat.c \
            ft_list_create_elem.c \
            ft_list_destroy.c \
            ft_list_dup.c \
            ft_list_find.c \
            ft_list_find_sublist.c \
            ft_list_foreach.c \
            ft_list_foreach_if.c \
            ft_list_foreach_ref.c \
            ft_list_last.c \
            ft_list_new.c \
            ft_list_prepend.c \
            ft_list_push_back.c \
            ft_list_push_front.c \
            ft_list_push_strs.c \
            ft_list_remove_if.c \
            ft_list_remove_sublist.c \
            ft_list_replace_sublist.c \
            ft_list_reverse.c \
            ft_list_reverse_fun.c \
            ft_list_size.c \
            ft_list_sort.c \
            ft_list_utils1.c \
            ft_list_utils2.c \
            ft_sorted_list_insert.c \
            ft_sorted_list_merge.c

FT_SRCS    += $(FILES:%.c=$(dir $(lastword $(MAKEFILE_LIST)))%.c)
