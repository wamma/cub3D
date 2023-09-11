NAME = cub3D

CC = cc
CFLAG = -g -Wall -Wextra -Werror
RM = rm -f
LIB_DIR = ../libft
LIBFLAG = -lft -L$(LIB_DIR)

SRCS = main.c error.c check_map.c check_extension.c parse_map.c init.c \
	  utils.c parse_utils.c free.c
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