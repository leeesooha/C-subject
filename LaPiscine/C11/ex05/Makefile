CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SOURCE = $(wildcard *.c)
OBJECT = $(SOURCE:.c=.o)
NAME = do-op

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -g $< -o $@

$(NAME): $(OBJECT)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all
