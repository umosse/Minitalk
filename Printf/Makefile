# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umosse <umosse@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 09:58:40 by umosse            #+#    #+#              #
#    Updated: 2023/11/30 15:49:51 by umosse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
SRCS = ft_functions_base.c ft_functions.c ft_is1.c ft_is2.c ft_printf.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re