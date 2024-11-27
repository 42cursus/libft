# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 00:38:57 by abelov            #+#    #+#              #
#    Updated: 2024/06/14 17:49:22 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# string sources
FILES	= ft_bsdstr.c \
              ft_bzero.c \
              ft_mem.c \
              ft_split.c \
              ft_strcat.c \
              ft_strchr.c \
              ft_strcmp.c \
              ft_strcpy.c \
              ft_strdup.c \
              ft_striteri.c \
              ft_strjoin.c \
              ft_strlen.c \
              ft_strmapi.c \
              ft_strncat.c \
              ft_strncmp.c \
              ft_strncpy.c \
              ft_strndup.c \
              ft_strnew.c \
              ft_strnstr.c \
              ft_strspn.c \
              ft_strstr.c \
              ft_strtok.c \
              ft_strtrim.c \
              ft_substr.c

FT_SRCS    += $(FILES:%.c=$(dir $(lastword $(MAKEFILE_LIST)))%.c)
