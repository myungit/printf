# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 00:41:10 by mpark-ki          #+#    #+#              #
#    Updated: 2020/02/27 03:51:57 by mpark-ki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
SRC =  		ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
	   		ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c \
	   		ft_memccpy.c ft_memcpy.c ft_memmove.c ft_memset.c \
	   		ft_strlcpy.c ft_strlen.c ft_tolower.c ft_toupper.c ft_memchr.c \
	   		ft_memcmp.c ft_strlcat.c ft_strnlen.c ft_strchr.c ft_strrchr.c \
	   		ft_strnstr.c ft_strncmp.c ft_calloc.c ft_strdup.c ft_substr.c \
	   		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_power.c ft_strmapi.c \
	   		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_allcaps.c ft_iscaps.c ft_free.c ft_positiv.c ft_putchar.c \
			ft_putstr.c ft_join.c

BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

SRC_OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): 
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $@ $(SRC_OBJS)
	ranlib $@

.PHONY: bonus
bonus: 
	$(CC) $(CFLAGS) -c $(SRC) $(BONUS_SRC) 
	ar rc $(NAME) $(SRC_OBJS) $(BONUS_OBJS)
	ranlib $(NAME)

.PHONY: clean
clean:
	/bin/rm -f *.o

.PHONY: fclean
fclean: clean
	/bin/rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: rebonus
rebonus: fclean bonus 
