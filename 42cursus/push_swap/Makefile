SRCS =	main.c instructions1.c instructions2.c instructions3.c greedy_utils.c \
		hard_coding_utils.c parsing_utils1.c parsing_utils2.c print_cmd_utils.c \
		push_swap_utils.c rarra_cnt_utils.c select_b_utils.c rarra_cnt_utils.c \
		select_b_utils.c move_pa_utils.c

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
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(ARNAME) : $(OBJS)
	cd $(LIB_DIR) ; make all
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