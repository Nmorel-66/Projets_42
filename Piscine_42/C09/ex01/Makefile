LIB = libft.a
SRC_DIR = srcs
INCLUDE_DIR = includes
SRC =  ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(LIB)

$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)

%.o: $(SRC_DIR)/%.c $(INCLUDE_DIR)/ft.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(LIB)

re:	fclean all
