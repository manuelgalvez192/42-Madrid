# The name of your library
NAME = pipex

# The C compiler to use
CC = cc

# The flags to use with the C compiler
CFLAGS = -Wall -Wextra -Werror

# The command to remove files
RM = rm -rf

# A list of all .o files that correspond to the .c files
OBJS = $(SRCS:.c=.o)

# A rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# A list of all .c files in the current directory
SRCS = main.c \
		path.c \
		split.c \
		check.c \

# The default target - builds the library
all: $(NAME)

# A rule to build the library from the .o files
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# A rule to remove all .o files
clean:
	$(RM) $(OBJS)

# A rule to remove all .o files and the library
fclean: clean
	$(RM) $(NAME)

# A rule to rebuild everything from scratch
re: fclean all

# A special rule to tell make that these targets aren't files
.PHONY: all fclean re clean