SRCS =	ft_printf.c \
		ft_put_addrhex.c \
		ft_put_hex.c \
		ft_unsigned_putnbr_fd.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_strlen.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGE = -Wall -Wextra -Werror
NAME = libftprintf.a
AR = ar
ARFLAGE = rc

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGE) -c $^ -o $@

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGE) $@ $^

clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re