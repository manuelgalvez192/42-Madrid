# The name of your project
NAME = philo

# The C compiler to use
CC = cc

# The flags to use with the archiver
ARFLAGS = -rc

# The flags to use with the C compiler
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

# The command to remove files
RM = rm -f

# A list of all .c files in the current directory
SRCS =	main.c 				\
		parse.c 			\
		philo_controller.c 	\
		philo_tasks.c		\
		start_simulation.c 	\
		cleaner.c			\

# A list of all .o files that correspond to the .c files
OBJS = $(SRCS:.c=.o)

# The default target - builds the project
all: $(NAME)

# A rule to build the project from the .o files
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

# A rule to remove all .o files
clean:
	$(RM) $(OBJS)

# A rule to remove all .o files and the project
fclean: clean
	$(RM) $(NAME)

# A rule to rebuild everything from scratch
re: fclean all

# A special rule to tell make that these targets aren't files
.PHONY: all fclean re clean
