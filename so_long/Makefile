# The name of your project
NAME = so_long
MAP = map.ber
LIBFT = ./libft/
LIBFT_LIB = $(LIBFT)libft.a
LIBMLX	:= ./MLX42
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

# The C compiler to use
CC = gcc -g3

# The flags to use with the archiver
ARFLAGS = -rc

# The flags to use with the C compiler
CFLAGS = -Wall -Wextra -Werror

# The command to remove files
RM = rm -f

# A list of all .c files in the current directory
SRCS = main.c \
	   game_manager.c \
	   error_manager.c \
	   error_free.c \
	   images_manager.c \
	   flood_fill.c \
	   player_movement.c \

# A list of all .o files that correspond to the .c files
OBJS = $(SRCS:.c=.o)

# A list of all .o files of bonus
BNS = $(BONUS:.c=.o)

# The default target - builds the project
all: $(NAME)

# A rule to build the project from the .o files
$(NAME): $(LIBFT_LIB) $(MLX_LIB) libmlx $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) $(LIBFT_LIB) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT_LIB):
	make -C $(LIBFT) -f Makefile

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# A rule to build the bonus part
bonus: $(BNS)
	$(CC) $(CFLAGS) $(BNS) -o $(NAME) $(LIBFT_LIB) $(LDFLAGS) $(LIBS)

# A rule to remove all .o files
clean:
	$(RM) $(OBJS) $(BNS)
	make -C $(LIBFT) clean
	make -C $(LIBMLX)/build clean

# A rule to remove all .o files and the project
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

# A rule to rebuild everything from scratch
re: fclean all

# A rule to run the program
run: all
	./$(NAME) $(MAP)

error: all
	@echo
	-./$(NAME)
	@echo
	-./$(NAME) maps/invalid/.ber
	@echo
	-./$(NAME) maps/invalid/no_extension
	@echo
	-./$(NAME) maps/invalid/other_extension.txt
	@echo
	-./$(NAME) maps/invalid/no_file.ber
	@echo
	chmod 000 maps/invalid/change_permissions.ber
	-./$(NAME) maps/invalid/change_permissions.ber
	@chmod 644 maps/invalid/change_permissions.ber
	@echo
	-./$(NAME) maps/invalid/empty.ber
	@echo
	-./$(NAME) maps/invalid/not_surrounded.ber
	@echo
	-./$(NAME) maps/invalid/not_rectangular0.ber
	@echo
	-./$(NAME) maps/invalid/not_rectangular1.ber
	@echo
	-./$(NAME) maps/invalid/no_collectibles.ber
	@echo
	-./$(NAME) maps/invalid/no_starting_position.ber
	@echo
	-./$(NAME) maps/invalid/two_starting_positions.ber
	@echo
	-./$(NAME) maps/invalid/no_exit.ber
	@echo
	-./$(NAME) maps/invalid/two_exits.ber
	@echo
	-./$(NAME) maps/invalid/other_characters.ber
	@echo
	-./$(NAME) maps/invalid/no_path.ber
	@echo

# A special rule to tell make that these targets aren't files
.PHONY: all fclean re clean bonus run
