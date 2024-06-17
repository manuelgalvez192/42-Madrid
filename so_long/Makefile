# The name of your project
NAME = so_long
MAP = map.ber
LIBFT = ./libft/
LIBFT_LIB = $(LIBFT)libft.a

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

# A list of all .o files that correspond to the .c files
OBJS = $(SRCS:.c=.o)

# A list of all .o files of bonus
BNS = $(BONUS:.c=.o)

# The default target - builds the project
all: $(NAME)
	./$(NAME) $(MAP)

# A rule to build the project from the .o files
$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)

$(LIBFT_LIB):
	make -C $(LIBFT) -f Makefile

# A rule to build the bonus part
bonus: $(BNS)
	$(CC) $(CFLAGS) -o $(NAME) $(BNS) $(LIBFT_LIB)

# A rule to remove all .o files
clean:
	$(RM) $(OBJS) $(BNS)
	make -C $(LIBFT) clean

# A rule to remove all .o files and the project
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

# A rule to rebuild everything from scratch
re: fclean all

# A rule to run the program
run: all
	./$(NAME) $(MAP)

# A special rule to tell make that these targets aren't files
.PHONY: all fclean re clean bonus run
