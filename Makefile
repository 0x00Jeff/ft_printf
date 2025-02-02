# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afatimi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 18:31:39 by afatimi           #+#    #+#              #
#    Updated: 2023/03/22 14:49:44 by afatimi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC	= ft_printf.c ds_operations.c libft.c libft2.c libft3.c args_operations.c dispatcher.c ft_itoa.c print_hex.c

M_SRC	= $(SRC) helpers.c
B_SRC	= $(SRC) helpers_bonus.c

M_OBJ	= $(M_SRC:.c=.o)
B_OBJ	= $(B_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(M_OBJ)
	ar rc $(NAME) $(M_OBJ)

bonus : $(B_OBJ)
	ar rc $(NAME) $(B_OBJ)

clean :
	rm -rf $(M_OBJ) $(B_OBJ)
fclean : clean
	rm -rf $(NAME)

args_operations.o ft_printf.o : args_operations.h
dispatcher.o ds_operations.o ft_printf.o helpers.o helpers_bonus.o: ds_operations.h
args_operations.o dispatcher.o ds_operations.o helpers.o helpers_bonus.o: helpers.h
print_hex.o ft_printf.o: print_hex.h
args_operations.o dispatcher.o helpers.o helpers_bonus.o: dispatcher.h
ft_itoa.o ft_printf.o print_hex.o: ft_printf.h
$(M_OBJ):	libft.h
$(B_OBJ):	libft.h

re : fclean all
.PHONY: clen fclean re all bonus
