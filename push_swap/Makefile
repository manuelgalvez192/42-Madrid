# The name of your project
NAME = push_swap
LIBFT_PATH = ./libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a

# The C compiler to use
CC = cc

# The flags to use with the archiver
ARFLAGS = -rc

# The flags to use with the C compiler
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

# The command to remove files
RM = rm -f

# A list of all .c files in the current directory
SRCS = main.c \
	   swap.c \
	   push.c \
	   rotate.c \
	   rev_rotate.c \
	   parse.c \
	   error.c \
	   ft_utils.c \

# A list of all .o files that correspond to the .c files
OBJS = $(SRCS:.c=.o)

# The default target - builds the project
all: $(NAME)

# A rule to build the project from the .o files
$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) $(LIBFT_LIB)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT_LIB):
	make -C $(LIBFT_PATH) -f Makefile

# A rule to remove all .o files
clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_PATH) clean

# A rule to remove all .o files and the project
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

# A rule to rebuild everything from scratch
re: fclean all

# A special rule to tell make that these targets aren't files
.PHONY: all fclean re clean