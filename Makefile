# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 21:34:31 by yuriiartymi       #+#    #+#              #
#    Updated: 2025/12/05 21:07:20 by yuriiartymi      ###   ########.fr        #
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
		ft_printf_utils.c \
		
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
	${CC} ${OFLAGS} main.o -L. -lftprintf -o $@

cl: fclean
	make fclean -C ${LIBFT_DIR} 
	${DEL} main.o main

fclean: clean
	${DEL} ${NAME}

clean:
	${DEL} ${OBJS}

re: fclean all

.PHONY: all fclean clean re main cl
