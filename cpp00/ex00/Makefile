# Nombre del proyecto
NAME = megaphone

# Compilador de C++
CXX = c++

# Flags para el compilador
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Comando para eliminar archivos
RM = rm -f

# Archivos fuente
SRCS = megaphone.cpp

# Archivos objeto
OBJS = $(SRCS:.cpp=.o)

# Target por defecto
all: $(NAME)

# Cómo compilar el binario
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Cómo compilar archivos .o a partir de .cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

# Limpiar archivos objeto
clean:
	$(RM) $(OBJS)

# Limpiar todo (binario + objetos)
fclean: clean
	$(RM) $(NAME)

# Recompilar desde cero
re: fclean all

# Asegura que estos nombres no son archivos
.PHONY: all clean fclean re
