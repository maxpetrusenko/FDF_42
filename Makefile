# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: max_p <max_p@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/09 21:22:02 by mpetruse          #+#    #+#              #
#    Updated: 2019/04/12 20:50:06 by max_p            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
# CFLAGS = -Wall -Werror -Wextra
SRC = main.c
HEADERS = includes/fdf.h
LIBFT = libft/libft.a
MINILIBX = minilibx/liblmx.a
OBJ=$(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(MINILIBX) $(OBJ)
		Make -C libft
		Make -C minilibx
		$(CC) $(CFLAGS) $(SRC) -o $(NAME) -I $(HEADERS) -L. $(LIBFT) -L ./minilibx -lmlx -framework OpenGL -framework AppKit

$(OBJ): $(LIBFT)
		$(CC) $(FLAGS) -c $(SRC)
$(LIBFT):
		make libft
$(MINILIBX):
		make minilibx

.PHONY : clean fclean re

clean :
		-rm -f $(OBJ)
		@echo "$(GREEN)All object files are deleted"

fclean : clean
		make fclean -C libft
		-rm -f $(NAME)
		@echo "$(GREEN)Cleaned everything"

re : fclean all