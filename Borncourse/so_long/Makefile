SRCS = main.c free.c map_init.c arg_check.c creat_filehash.c key_hook.c \
		map_print.c game_end_check.c

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lz
MLX_A = libmlx.dylib
CC = cc
NAME = so_long
AR = ar
ARFLAGS = rc
LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(MLX_A)
	cd libft; make;
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_A) $(MLX_FLAGS) -o $(NAME)

$(MLX_A) :
	cd minilibx_mms_20210621; make

clean :
	cd minilibx_mms_20210621; make clean
	cd libft; make clean
	rm -rf $(OBJS)

fclean : clean
	cd libft; make fclean
	cd minilibx_mms_20210621; make fclean
	rm -rf $(NAME)

re :
	make fclean
	make all