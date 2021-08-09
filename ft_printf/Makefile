# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungsle <seungsle@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/28 22:37:54 by seungsle          #+#    #+#              #
#    Updated: 2021/07/28 23:30:35 by seungsle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
CC = gcc
SRC = ft_parse.c \
			ft_parse_flags.c \
			ft_print_chars.c \
			ft_print_num.c \
			ft_print_num_util.c \
			ft_print_persent.c \
			ft_print_variable.c \
			ft_printf.c \
			ft_printf_utils.c \
			ft_atoi.c \
			ft_isdigit.c \
			ft_itoa.c \
			ft_itoa_un.c \
			ft_memchr.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_strchr.c \
			ft_strchr_size.c \
			ft_strlen.c

SRC_B = ft_parse_bonus.c \
				ft_parse_flags_bonus.c \
				ft_print_chars_bonus.c \
				ft_print_num_bonus.c \
				ft_print_num_util_bonus.c \
				ft_print_persent_bonus.c \
				ft_print_variable_bonus.c \
				ft_printf_bonus.c \
				ft_printf_utils_bonus.c \
				ft_atoi_bonus.c \
				ft_isdigit_bonus.c \
				ft_itoa_bonus.c \
				ft_itoa_un_bonus.c \
				ft_memchr_bonus.c \
				ft_putchar_bonus.c \
				ft_putstr_bonus.c \
				ft_strchr_bonus.c \
				ft_strchr_size_bonus.c \
				ft_strlen_bonus.c

OBJECTS = $(SRC:%.c=%.o)

OBJECTS_B = $(SRC_B:%.c=%.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJECTS) $(OBJECTS_B)
else
	OBJ_FILES = $(OBJECTS)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	ar -rcs $(NAME) $(OBJ_FILES)

bonus :
	make WITH_BONUS=1 all

clean :
	rm -f $(OBJECTS) $(OBJECTS_B)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re
