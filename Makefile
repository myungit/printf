# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 20:20:34 by mpark-ki          #+#    #+#              #
#    Updated: 2019/11/21 15:58:14 by mpark-ki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
SRC_DIR = ./src/
OBJS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
	   ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c \
	   ft_memccpy.c ft_memcpy.c ft_memmove.c ft_memset.c \
	   ft_strlcpy.c ft_strlen.c ft_tolower.c ft_toupper.c ft_memchr.c \
	   ft_memcmp.c ft_strlcat.c ft_strnlen.c ft_strchr.c ft_strrchr.c \
	   ft_strnstr.c ft_strncmp.c ft_calloc.c ft_strdup.c ft_substr.c \
	   ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_power.c ft_strmapi.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
HEADER = libft.h
FILES = $(patsubst %, $(SRC_DIR)%, $(OBJS))


all: $(NAME)

$(NAME): 
	$(CC) $(CFLAGS) -c $(FILES)
	ar rc $(NAME) *.o
	ranlib $(NAME)
	$(CC) main.c -L. $(NAME)

.PHONY: clean
clean:
	/bin/rm -f *.o

.PHONY: fclean
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
