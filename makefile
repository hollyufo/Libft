# Name of the library
NAME = libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files and object files
SRC = ft_strlen.c ft_memset.c ft_bzero.c 
OBJ = $(SRC:.c=.o)

# Rule to create the library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)  # 'ar' creates a static library

# Rule to compile all
all: $(NAME)

# Rule to remove object files
clean:
	rm -f $(OBJ)

# Rule to remove object files and the library
fclean: clean
	rm -f $(NAME)

# Rule to rebuild the library
re: fclean all