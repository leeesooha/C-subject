SRCS =	main.c free.c map_init.c arg_check.c creat_filehash.c key_hook.c \
		map_print.c game_end_check.c valid_path_search.c \
		my_str_put_windows.c enemy.c
SRCS_BONUS = main_bonus.c free_bonus.c map_init_bonus.c arg_check_bonus.c \
		creat_filehash_bonus.c key_hook_bonus.c map_print_bonus.c \
		game_end_check_bonus.c valid_path_search_bonus.c \
		my_str_put_windows_bonus.c enemy_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lz
MLX_A = ./minilibx_opengl/libmlx.a
CC = cc
NAME = so_long
AR = ar
ARFLAGS = rc
LIBFT_A = ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(MLX_A) $(LIBFT_A)
	cd libft; make;
	$(CC) $(CFLAGS) $(MLX_FLAGS) $^ -o $(NAME)

$(MLX_A) :
	cd minilibx_opengl; make

$(LIBFT_A) :
	cd ./libft; make all

bonus : $(OBJS_BONUS) $(MLX_A) $(LIBFT_A)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $^ -o $(NAME)
	touch bonus;

clean :
	cd minilibx_opengl; make clean
	cd libft; make clean
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	cd libft; make fclean
	cd minilibx_opengl; make fclean
	rm -rf $(NAME) bonus

re :
	make fclean
	make all