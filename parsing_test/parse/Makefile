NAME = cub3D

CC = cc
CFLAG = -g -Wall -Wextra -Werror
RM = rm -f
LIB_DIR = ../../libft
LIBFLAG = -lft -L$(LIB_DIR)

SRCS = ft_error.c ft_free.c ft_split_white_space.c \
		init.c main.c \
		parse_check.c parse_get.c parse_info_map.c parse_utils.c

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