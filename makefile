# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 16:35:57 by hyungjup          #+#    #+#              #
#    Updated: 2023/09/05 16:30:12 by eoh              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAG = -Wall -Wextra -Werror
RM = rm -f
MLX = -L. -lmlx -framework OpenGL -framework AppKit
LIB_DIR = ./libft
LIBFLAG = -lft -L$(LIB_DIR)

SRCS = main.c srcs/error.c srcs/init.c srcs/utils.c parsing/get_path.c parsing/map_utils.c parsing/parse_map.c
OBJS = $(SRCS:.c=.o)

HEADER = cub3D.h

all : $(NAME)

$(NAME): $(OBJS)
	make -C mlx
	make -C $(LIB_DIR)
	mv ./mlx/libmlx.dylib ./libmlx.dylib
	$(CC) $(CFLAG) -o $@ $^ $(MLX) $(LIBFLAG)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ -I $(HEADER)


clean :
	$(RM) $(OBJS)
	make -C ./mlx clean
	make -C ./libft fclean
	rm -rf libmlx.dylib
fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
