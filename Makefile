# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yartym <yartym@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/29 09:52:09 by yartym            #+#    #+#              #
#    Updated: 2026/01/29 09:52:11 by yartym           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
AR = ar -rcs
CFLAGS = -Wall -Werror -Wextra
DEL = rm -rf
LIBFT_DIR = ./libft
LIBFT = ${LIBFT_DIR}/libft.a
INCLUDES = -Iincludes
OBJ_DIR = obj
SRC_DIR = src

SRCS = ft_printf.c \
		len.c \
		print.c \
		put.c \
		format.c \
		padding.c \
		is.c \

OBJS := $(addprefix ${OBJ_DIR}/, ${SRCS:.c=.o})

all: ${NAME}

bonus: all

${OBJ_DIR}:
	mkdir -p $@

${NAME}: ${OBJS}
	make -C ${LIBFT_DIR}
	cp ${LIBFT} ${NAME}
	${AR} ${NAME} ${OBJS}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIR}
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

fclean: clean
	${DEL} ${NAME}

clean:
	make fclean -C ${LIBFT_DIR}
	${DEL} ${OBJ_DIR}

re: fclean all

main: all
	${CC} main.c libftprintf.a -o $@

.PHONY: all fclean clean re bonus main
