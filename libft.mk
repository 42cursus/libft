# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 00:07:18 by abelov            #+#    #+#              #
#    Updated: 2024/11/25 00:24:33 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_SRCS	 		:=
FT_DIRS			:= ctype io list std string tab

include $(FT_DIRS:%=$(LIBFT_PREFIX)%/Makefile.mk)
