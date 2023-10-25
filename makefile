NAME = cub3D

CC = cc
CFLAG = -Wall -Wextra -Werror -g #-fsanitize=address
RM = rm -f
MLX = -L. -lmlx -framework OpenGL -framework AppKit
LIB_DIR = ./libft
LIBFLAG = -lft -L$(LIB_DIR)

SRCS = main.c \
	   srcs/key_event.c srcs/load_image.c srcs/main_loop.c srcs/calculate.c\
	   srcs/ft_error.c srcs/ft_free.c srcs/ft_init.c srcs/ft_init2.c \
	   srcs/calculate_utils.c \
	   parse/ft_split_white_space.c \
	   parse/parse_check.c parse/parse_check2.c parse/parse_get.c parse/parse_info_map.c \
	   parse/parse_utils.c parse/parse_utils2.c\
	   parse/parse_check_map.c parse/parse_map.c parse/parse_get_map.c \
	   parse/check_surround_by_wall.c

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
