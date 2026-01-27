# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 21:34:31 by yuriiartymi       #+#    #+#              #
#    Updated: 2026/01/27 13:55:55 by yartym           ###   ########.fr        #
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
		utils.c \
		put.c \
		converters.c \
		format.c \
		padding.c \

OBJS := ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	make -C ${LIBFT_DIR}
	cp ${LIBFT} ${NAME}
	${AR} ${NAME} ${OBJS}

${OBJS}: %.o: %.c
	${CC} ${OFLAGS} -c $< -o $@

main: all
	${CC} ${OFLAGS} -c main.c
	${CC} ${OFLAGS} -g main.o -L. -lftprintf -o $@

cl: fclean
	make fclean -C ${LIBFT_DIR}
	${DEL} main.o main

fclean: clean
	${DEL} ${NAME}

clean:
	${DEL} ${OBJS}

re: fclean all

.PHONY: all fclean clean re main cl
