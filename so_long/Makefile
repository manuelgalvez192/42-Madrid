# The name of your project
NAME = so_long
MAP = map.ber
LIBFT = ./libft/
LIBFT_LIB = $(LIBFT)libft.a
MLX = ./mlx/
MLX_LIB = $(MLX)libmlx.a

# The C compiler to use
CC = gcc -g3

# The flags to use with the archiver
ARFLAGS = -rc

# The flags to use with the C compiler
CFLAGS = -Wall -Wextra -Werror -I mlx

# The flags to use for linking
LDFLAGS = -Lmlx -L/usr/X11R6/lib -lmlx -lXrandr -lXrender -lXext -lX11 -lm -lbsd

# The command to remove files
RM = rm -f

# A list of all .c files in the current directory
SRCS = main.c \
	   game_manager.c \
	   error_manager.c \
	   error_free.c \
	   images_manager.c \
	   mlx/mlx_init.c \
	   mlx/mlx_new_window.c \

# A list of all .o files that correspond to the .c files
OBJS = $(SRCS:.c=.o)

# A list of all .o files of bonus
BNS = $(BONUS:.c=.o)

# The default target - builds the project
all: $(NAME)
	./$(NAME) $(MAP)

# A rule to build the project from the .o files
$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_LIB) $(LDFLAGS)

$(LIBFT_LIB):
	make -C $(LIBFT) -f Makefile

$(MLX_LIB):
	make -C $(MLX)

# A rule to build the bonus part
bonus: $(BNS)
	$(CC) $(CFLAGS) $(BNS) -o $(NAME) $(LIBFT_LIB) $(LDFLAGS)

# A rule to remove all .o files
clean:
	$(RM) $(OBJS) $(BNS)
	make -C $(LIBFT) clean
	make -C $(MLX) clean

# A rule to remove all .o files and the project
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean
	make -C $(MLX) clean

# A rule to rebuild everything from scratch
re: fclean all

# A rule to run the program
run: all
	./$(NAME) $(MAP)

# A special rule to tell make that these targets aren't files
.PHONY: all fclean re clean bonus run
