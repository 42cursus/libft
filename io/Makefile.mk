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

# stdio sources
#VPATH   := $(VPATH):${LIBFTSRCDIR}/io

#SRCS    += $(patsubst %.c,io/%.c,$(FILES))
FILES   = ft_fd1.c \
           ft_fd2.c \
           ft_printf.c \
           ft_printf_utils1.c \
           ft_printf_utils2.c \
           ft_print_hex.c \
           ft_print_unsigned.c \
           get_next_line_utils.c \
           get_next_line.c

SRCS    += $(patsubst %.c,io/%.c,$(FILES))