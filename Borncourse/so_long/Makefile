SRCS = main.c free.c map_check.c

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = cc
NAME = so_long
AR = ar
ARFLAGS = rc
LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	cd libft; make;
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean :
	cd libft; make clean
	rm -rf $(OBJS)

fclean : clean
	cd libft; make fclean
	rm -rf $(NAME)

re :
	make fclean
	make all