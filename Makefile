# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 21:34:31 by yuriiartymi       #+#    #+#              #
#    Updated: 2026/01/28 08:59:15 by yartym           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
AR = ar -rcs
OFLAGS = -Wall -Werror -Wextra
DEL = rm -f
LIBFT_DIR = ./libft
LIBFT = ${LIBFT_DIR}/libft.a

SRCS = ft_printf.c \
		len.c \
		print.c \
		put.c \
		format.c \
		padding.c \
		is.c \

OBJS := ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	make -C ${LIBFT_DIR}
	cp ${LIBFT} ${NAME}
	${AR} ${NAME} ${OBJS}

${OBJS}: %.o: %.c
	${CC} ${OFLAGS} -c $< -o $@

fclean: clean
	${DEL} ${NAME}

clean:
	make fclean -C ${LIBFT_DIR}
	${DEL} ${OBJS}

re: fclean all

# main: all
# 	${CC} ${OFLAGS} -g main.c -L. -lftprintf -o $@
.PHONY: all fclean clean re
