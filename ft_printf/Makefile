# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 09:04:35 by mpark-ki          #+#    #+#              #
#    Updated: 2020/02/27 22:47:46 by mpark-ki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
SRC =  		ft_ftoa.c ft_ltoa.c ft_uitoa.c ft_xitoa.c ft_ouitoa.c \
			ft_printf_format.c ft_save_fwp.c ft_printf.c ft_getsign.c \
			ft_getvalue.c ft_is_diuoxf.c ft_is_pencs.c \
			ft_is_percentspeciflagwp.c

SRC_OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): 
	make -C ../
	mv ../libft.a ./$(NAME)
	$(CC) $(CFLAGS) -c $(SRC) 
	ar rc $@ $(SRC_OBJS)
	ranlib $@

.PHONY: clean
clean:
	make -C ../ clean
	/bin/rm -f *.o

.PHONY: fclean
fclean: clean
	make -C ../ fclean
	/bin/rm -f $(NAME) libft.a

.PHONY: re
re: fclean all
