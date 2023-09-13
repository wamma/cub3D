NAME = cub3D

CC = cc
CFLAG = -g -Wall -Wextra -Werror
RM = rm -f
LIB_DIR = ../libft
LIBFLAG = -lft -L$(LIB_DIR)

SRCS = main.c ft_error.c check_valid_path.c get_texture_info.c init.c \
		  parsing_utils.c split_white_space.c ft_free.c
OBJS = $(SRCS:.c=.o)

HEADER = test.h

all : $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB_DIR)
	$(CC) $(CFLAG) -o $@ $^ $(LIBFLAG)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ -I $(HEADER)

clean :
	$(RM) $(OBJS)
	make -C ./libft fclean
fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re