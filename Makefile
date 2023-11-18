# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 20:29:32 by abelov            #+#    #+#              #
#    Updated: 2023/11/20 15:50:09 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CC := cc
CFLAGS := -Wall -Wextra -Werror -g
LIB_COMMAND := ar rcs
RM := rm -f

SRC_FILES := ft_atoi.c \
			 ft_itoa.c \
             ft_bzero.c \
             ft_isctype.c \
             ft_mem.c \
             ft_fd1.c \
             ft_fd2.c \
             ft_strdup.c \
             ft_split.c \
             ft_str1.c \
             ft_str2.c \
             ft_str3.c \
             ft_calloc.c

OBJ_FILES = $(SRC_FILES:.c=.o)
ASM_FILES = $(SRC_FILES:.c=.s)

BONUS			= ft_lst1.c \
 				  ft_lst2.c
BONUS_OBJS		= $(BONUS:.c=.o)
BONUS_ASM		= $(BONUS:.c=.s)

all: $(NAME)

$(OBJ_FILES): %.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

bonus:	.bonus

.bonus: $(OBJS) $(BONUS_OBJS)
		$(LIB_COMMAND) $(NAME) $(OBJS) $(BONUS_OBJS)
		touch $@

$(NAME): $(OBJ_FILES)
	$(LIB_COMMAND) $(NAME) $(OBJ_FILES)

clean:
	/bin/rm -f $(OBJ_FILES) $(BONUS_OBJS) $(ASM_FILES) $(BONUS_ASM)

fclean: clean
	/bin/rm -f $(NAME) a.out .bonus

re: fclean all

.PHONY: all clean flean re bonus
