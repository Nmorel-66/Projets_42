# Nom de la bibliothèque
NAME = libftprintf.a

# Compilateur et options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Commandes
AR = ar rcs
RM = rm -f

# Fichiers sources
SRCS = ft_printf.c

# Fichiers objets
OBJS = $(SRCS:.c=.o)

# Fichier header
HEADERS = libftprintf.h

# Cible par défaut
all: $(NAME)

# Création de la bibliothèque
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "Création de $(NAME) terminée."

# Compilation des fichiers .c en .o
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	$(RM) $(OBJS)
	@echo "Fichiers objets supprimés."

# Nettoyage complet
fclean: clean
	$(RM) $(NAME)
	@echo "$(NAME) supprimée."

# Recompilation complète
re: fclean all

# Commandes
.PHONY: all clean fclean re
