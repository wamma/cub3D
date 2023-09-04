# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 16:35:57 by hyungjup          #+#    #+#              #
#    Updated: 2023/08/30 17:34:33 by hyungjup         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAG = -Wall -Wextra -Werror
RM = rm -f
MLX = -L. -lmlx -framework OpenGL -framework AppKit

SRCS = 


OBJS = $(SRCS:.c=.o)

HEADER = fractol.h

all : $(NAME)

$(NAME): $(OBJS)
	make -C mlx
	mv ./mlx/libmlx.dylib ./libmlx.dylib
	$(CC) $(CFLAG) -o $@ $^ $(MLX)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ -I $(HEADER)


clean :
	$(RM) $(OBJS)
	make -C ./mlx clean
	rm -rf libmlx.dylib
	echo "$(YELLOW)object files deleted!"

fclean : clean
	$(RM) $(NAME)
	echo "$(RED)all deleted"

re : fclean all

.PHONY : all clean fclean re

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[0;33m