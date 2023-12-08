# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 20:29:32 by abelov            #+#    #+#              #
#    Updated: 2023/11/20 15:50:09 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= libft.a
CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -g
LIB_COMMAND		:= ar rcs
RM				:= /bin/rm

SRC_FILES 		:= ft_atoi.c \
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

OBJ_DIR			=	obj
OBJS			= $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

ASM_FILES		= $(SRC_FILES:.c=.s)

BONUS			= ft_lst1.c \
					ft_lst2.c

BOBJ			= $(BONUS:%.c=$(OBJ_DIR)/%.o)
BONUS_ASM		= $(BONUS:.c=.s)

all: $(NAME)

$(OBJ_DIR):
		mkdir -pv $(OBJ_DIR)
$(OBJ_DIR)/%.o: %.c
		$(CC) $(CFLAGS) -c $^ -o $@

bonus:	.bonus

.bonus: $(OBJS) $(BOBJ)
		$(LIB_COMMAND) $(NAME) $(OBJS) $(BOBJ)
		touch $@

$(NAME): $(OBJ_DIR) $(OBJS)
		$(LIB_COMMAND) $(NAME) $(OBJS)

clean:
		$(RM) -rf $(OBJ_DIR) $(ASM_FILES) $(BONUS_ASM)

fclean: clean
		$(RM) -f $(NAME) a.out .bonus

re: fclean all

.PHONY: all clean flean re bonus
