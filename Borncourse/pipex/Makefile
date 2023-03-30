SRCS = main.c creatdata.c cmd_check.c child.c free.c heredoc.c
SRCS_BONUS = main_bonus.c creatdata_bonus.c cmd_check_bonus.c \
		child_bonus.c free_bonus.c heredoc_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
NAME = pipex
ARNAME = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror
CC = cc

all : $(NAME)

$(NAME) : $(OBJS) $(ARNAME)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(ARNAME) :
	cd ./libft ; make all

bonus : $(OBJS_BONUS) $(ARNAME)
	$(CC) $(CFLAGS) $^ -o $(NAME)
	touch bonus;

clean :
	cd ./libft ; make clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean :
	cd ./libft ; make fclean
	rm -f $(NAME) bonus

re :
	make fclean
	make all