# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 16:34:50 by mpetruse          #+#    #+#              #
#    Updated: 2018/07/24 15:11:12 by mpetruse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
C = gcc

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -O2

SOURCES = ./src/*.c ./ft_printf/*.c

INCLUDE = header

OBJS = ./src/ft_*.o ./ft_printf/*.o

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SOURCES) -I $(INCLUDE)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
