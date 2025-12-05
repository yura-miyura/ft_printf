# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 18:12:56 by yuriiartymi       #+#    #+#              #
#    Updated: 2025/11/24 12:10:03 by yuriiartymi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CC := cc
AR := ar -rcs
FLAGS := -Wall -Werror -Wextra

SRCS = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

OBJC := ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJC}
	${AR} $@ $^

${OBJC}: %.o: %.c
	${CC} ${FLAGS} -c $< -o $@

fclean: clean
	rm -f ${NAME}

clean:
	rm -f ${OBJC} ${BONUS_OBJC}

re: fclean all

.PHONY: all fclean clean re bonus

# https://github.com/Tripouille/libftTester
# https://github.com/0x050f/libft-war-machine
# https://github.com/alelievr/libft-unit-test
# so:
# 	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(BOUNUS)
# 	gcc -nostartfiles -shared -o libft.so $(OBJC) $(BONUS_OBJC)
