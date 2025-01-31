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

LIBFTSRCDIR		= $(CURDIR)
BUILD_DIR		= build
OBJDIR			= $(BUILD_DIR)/objs
DEPDIR			= $(BUILD_DIR)/deps

CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -Wimplicit
INCLUDE_FLAGS	:= -I. -I./include -I./include/ft
DEBUG_FLAGS		:= -g3 -gdwarf-3
DEPFLAGS		= -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

ifdef BUILD_WITH_ASAN
DEBUG_FLAGS		:= -g3 -gdwarf-3 \
					-fasynchronous-unwind-tables \
					-fsanitize=address \
					-fsanitize=undefined \
					-fno-sanitize-recover \
					-fsanitize=float-divide-by-zero \
					-fsanitize=float-cast-overflow
else
DEBUG_FLAGS		:= -g3 -gdwarf-3
endif

CTAGS			:= ctags
LIB_COMMAND		:= ar rcsP
RM				:= /bin/rm

include ./libft.mk

BUILD_OBJS		= $(FT_SRCS:%.c=$(OBJDIR)/%.o)
BUILD_DEPS		= $(FT_SRCS:%.c=$(DEPDIR)/%.d)

# We need this for the output to go in the right place.  It will default to
# empty if make was configured to work with a cc that can't grok -c and -o
# together.  You can't compile the C library with such a compiler.
OUTPUT_OPTION	= -o $@

# https://make.mad-scientist.net/papers/advanced-auto-dependency-generation/
COMPILE.c		= $(CC) $(INCLUDE_FLAGS) $(DEPFLAGS) $(CFLAGS) \
 					$(DEBUG_FLAGS) $(TARGET_ARCH) -c

$(OBJDIR)/%.o : %.c
$(OBJDIR)/%.o : %.c $(DEPDIR)/%.d
		@if [ ! -d $(@D) ]; then \
  			mkdir -p $(@D); \
			mkdir -p $(@D:$(OBJDIR)%=$(DEPDIR)%); fi
		@$(COMPILE.c) $(OUTPUT_OPTION) $<

all: $(NAME)

$(BUILD_DEPS):

# Include dependency files
-include $(BUILD_DEPS)

$(NAME): $(BUILD_OBJS)
		@$(LIB_COMMAND) $(NAME) $(BUILD_OBJS)
		@echo "FTLIB BUILD COMPLETE!"

.PHONY: all clean flean re norm so

bonus: .bonus

.bonus:
	@touch $@

#so: $(BUILD_OBJS)
#	$(CC) -nostartfiles -fPIC $(CFLAGS) $(DEBUG_FLAGS) $(FT_SRCS) $(INCLUDE_FLAGS)
#	gcc -nostartfiles -shared $(DEBUG_FLAGS) -o libft.so $(BUILD_OBJS)

clean:
		@$(RM) -f $(BUILD_OBJS)
		@$(RM) -fr $(OBJDIR)

fclean: clean
		@$(RM) -fr $(NAME) $(DEPDIR) $(BUILD_DIR) a.out

re: fclean all

norm:
		@norminette --use-gitignore
