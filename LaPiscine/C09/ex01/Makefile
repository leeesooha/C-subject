CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRCDIR = $(addprefix ./srcs/, $(SRCS))
OBJS = $(SRCDIR:.c=.o)
HEADER = ./includes/
NAME = libft.a
AR = ar
ARFLAGS = rc

all : $(NAME)

%.o : %.c
		$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER)

$(NAME) : $(OBJS)
		$(AR) $(ARFLAGS) $@ $(OBJS)

clean :
		rm -f $(OBJS)
fclean : clean
		rm -f $(NAME)

re: fclean all
