# Nom de la bibliothèque
NAME = libft.a

# Compilateur et options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Commandes
AR = ar rcs
RM = rm -f

# Fichiers sources
SRCS = ft_isalpha.c \
       ft_isdigit.c \
       ft_isalnum.c \
       ft_isascii.c \
       ft_isprint.c \
       ft_strlen.c \
       ft_memset.c \
       ft_bzero.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_strlcpy.c \
       ft_strlcat.c \
       ft_tolower.c \
       ft_toupper.c \
       ft_strchr.c \
       ft_strncmp.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_strnstr.c \
       ft_atoi.c \
       ft_strdup.c \
       ft_substr.c \
       ft_strjoin.c \
       ft_strtrim.c \
       ft_split.c \
       ft_itoa.c \
       ft_strmapi.c \
       ft_striteri.c \
       ft_putchar_fd.c \
       ft_putstr_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c

# Fichier header
HEADERS = libft.h

# Fichiers objets
OBJS = $(SRCS:.c=.o)

# Cible par défaut
all: $(NAME)

# Création de la bibliothèque
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "Création de $(NAME) terminée."

# Compilation des fichiers .c en .o
%.o: %.c $(HEADERS)
	rm

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

# Indiquer que les commandes ne sont pas des fichiers
.PHONY: all clean fclean re
