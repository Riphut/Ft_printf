# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkandiyi <rkandiyi@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 21:50:40 by rkandiyi          #+#    #+#              #
#    Updated: 2023/01/07 21:35:47 by rkandiyi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_putfnc.c ft_errormsg.c\

CFLAGS =	-Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			
clean:
	rm -fr $(OBJS)
	
fclean:		clean
	rm -fr $(NAME)

re:		clean all