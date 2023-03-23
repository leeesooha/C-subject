SRCS = main.c argscheck.c free.c

NAME = pipex
ARNAME = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror
CC = cc

all : $(NAME)

$(NAME) : $(SRCS) $(ARNAME)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(ARNAME) :
	cd ./libft ; make all

clean :
	cd ./libft ; make clean

fclean :
	cd ./libft ; make fclean

re :
	make fclean
	make all