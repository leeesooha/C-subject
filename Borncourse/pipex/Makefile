SRCS = main.c creatdata.c cmd_check.c child.c free.c heredoc.c

NAME = pipex
ARNAME = ./libft/libft.a
CFLAGS = -g
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