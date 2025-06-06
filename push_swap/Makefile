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
	   checker.c \
	   error.c \
	   ft_utils.c \
	   math_utils.c \
	   list_utils.c \
	   algorithm.c \
	   sort.c \

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

error:
	@echo "==> TEST: No pasar argumentos"
	@./$(NAME) || echo "✅ Passed"

	@echo "==> TEST: Cadena vacía"
	@./$(NAME) "" || echo "✅ Passed"

	@echo "==> TEST: Separadores consecutivos"
	@./$(NAME) "   1  2   3" || echo "✅ Passed"

	@echo "==> TEST: Solo un argumento"
	@./$(NAME) "1" || echo "✅ Passed"

	@echo "==> TEST: Dos argumentos"
	@./$(NAME) "1 2" || echo "✅ Passed"

	@echo "==> TEST: Diez argumentos"
	@./$(NAME) 1 2 3 4 5 6 7 8 9 10 || echo "✅ Passed"

	@echo "==> TEST: Número no dígito (carácter)"
	@./$(NAME) "1 2 a 4" || echo "✅ Passed"

	@echo "==> TEST: Número positivo repetido con y sin signo"
	@./$(NAME) "1 +1" || echo "✅ Passed"

	@echo "==> TEST: Números repetidos"
	@./$(NAME) "1 2 2 3" || echo "✅ Passed"

	@echo "==> TEST: Número negativo y positivo repetido"
	@./$(NAME) "-1 1 1" || echo "✅ Passed"

	@echo "==> TEST: Números de gran rango (INT_MAX e INT_MIN válidos)"
	@./$(NAME) "2147483647 -2147483648" || echo "✅ Passed"

	@echo "==> TEST: Números fuera de rango positivos y negativos"
	@./$(NAME) "2147483648 -2147483649" || echo "✅ Passed"

	@echo "==> TEST: Lista ordenada (sin movimientos)"
	@./$(NAME) "1 2 3" || echo "✅ Passed"

	@echo "==> TEST: Lista inversa"
	@./$(NAME) "3 2 1" || echo "✅ Passed"

	@echo "==> TEST: Lista con duplicados positivos y negativos"
	@./$(NAME) "1 2 -2 2 -2 3" || echo "✅ Passed"

	@echo "==> TEST: Lista con un solo número (cero)"
	@./$(NAME) "0" || echo "✅ Passed"

	@echo "==> TEST: Cadena con múltiples espacios consecutivos"
	@./$(NAME) "  42   7 19    " || echo "✅ Passed"

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
.PHONY: all fclean re clean error