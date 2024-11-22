# The name of your library
NAME = libft.a

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
SRCS = ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_strlen.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strncmp.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strnstr.c\
		ft_atoi.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c\
		printf/ft_printf.c\
		printf/ft_printf_number.c\
		printf/ft_printf_pointer.c\
		getNextLine/get_next_line.c\
		getNextLine/get_next_line_utils.c

# A list of all .o files that correspond to the .c files
OBJS = $(SRCS:.c=.o)

# The default target - builds the library
all: $(NAME)

# A rule to build the library from the .o files
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

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
