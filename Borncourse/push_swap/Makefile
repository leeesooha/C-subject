SRCS = push_swap.c parsing.c parsing_utils.c\

CC = cc
CFLAGS = -Wall -Wextra -Werror
ARNAME = lib_push_swap.a
AR = ar
ARFLAGS = rc
OBJS = $(SRCS:.c=.o)
LIB_SRCS = ./libft/srcs
LIB_DIR = ./libft
NAME = push_swap

all : $(NAME)

$(NAME) : $(ARNAME)
	$(CC) $(CFLAGS) -o $@ $^ main.c -g3

%.o : %.c
	cd $(LIB_DIR) ; make all
	$(CC) $(CFLAGS) -c $^ -o $@ -g3

$(ARNAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^ $(LIB_SRCS)/*.o

clean :
	cd $(LIB_DIR) ; make clean
	rm -f $(OBJS)

fclean : clean
	cd $(LIB_DIR) ; make fclean
	rm -f $(ARNAME)

re: 
	cd $(LIB_DIR) ; make re
	$(MAKE) fclean
	make all