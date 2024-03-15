# The name of your library
NAME = libftprintf.a
LIBFT = ./Libft/
LIBFT_LIB = $(LIBFT)libft.a
# The C compiler to use
CC = gcc
# The archiver to use
AR = ar
# The flags to use with the archiver
ARFLAGS = -rc
# The flags to use with the C compiler
CFLAGS = -Wall -Wextra -Werror
# The command to remove files
RM = rm -f
# A list of all .c files in the current directory
SRCS = ft_printf.c\
		ft_print_number.c\
		ft_print_pointer.c
# A list of all .o files that correspond to the .c files
OBJS = $(SRCS:.c=.o)
# The default target - builds the library
all: $(NAME)
# A rule to build the library from the .o files
$(NAME): $(OBJS)
	make -C $(LIBFT) -f Makefile
	cp $(LIBFT_LIB) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
# A rule to remove all .o files
clean:
	$(RM) $(OBJS)
	make -C $(LIBFT) clean
# A rule to remove all .o files and the library
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean
# A rule to rebuild everything from scratch
re: fclean all
# A special rule to tell make that these targets aren't files
.PHONY: all fclean re clean
