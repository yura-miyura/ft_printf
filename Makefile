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
DEL = rm -f
LIBFT_DIR = ./libft
LIBFT = ${LIBFT_DIR}/libft.a
OBJ_DIR = obj

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

${OBJ_DIR}/%.o: %.c | ${OBJ_DIR}
	${CC} ${CFLAGS} -c $< -o $@

fclean: clean
	${DEL} ${NAME}

clean:
	make fclean -C ${LIBFT_DIR}
	${DEL} ${OBJS}

re: fclean all

main: all
	${CC} -g main.c -L. -lftprintf -o $@

.PHONY: all fclean clean re
