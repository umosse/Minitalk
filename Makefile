# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umosse <umosse@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 10:15:08 by umosse            #+#    #+#              #
#    Updated: 2024/02/12 15:46:24 by umosse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

SRCS_CLIENT = client.c
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
SRCS_SERVER = server.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -f

all: client server

client: $(OBJS_CLIENT) Libft/libft.a Printf/printf.a
	cc $(CFLAGS) -o client $(OBJS_CLIENT) Libft/libft.a Printf/libftprintf.a
server: $(OBJS_SERVER) Libft/libft.a Printf/printf.a
	cc $(CFLAGS) -o server $(OBJS_SERVER) Libft/libft.a Printf/libftprintf.a

Libft/libft.a:
	make -C Libft

Printf/printf.a:
	make -C Printf

clean:
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)
	cd Libft && make clean
	cd Printf && make clean

fclean : clean
	$(RM) client server
	cd Libft && make fclean
	cd Printf && make fclean

re: fclean all

.PHONY : all clean fclean re
