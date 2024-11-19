# Nom de la bibliothèque
NAME = libftprintf.a

# Répertoires
SRCDIR = Srcs
INCDIR = Includes
OBJDIR = Objs

# Compilateur et options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)

# Commandes
AR = ar rcs
RM = rm -f

# Fichiers sources et objets
SRCS = $(SRCDIR)/ft_printf.c \
       $(SRCDIR)/ft_printnbr.c \
       $(SRCDIR)/ft_printchar.c \
       $(SRCDIR)/ft_printstr.c \
       $(SRCDIR)/ft_printhex.c \
       $(SRCDIR)/ft_printptr.c \
       $(SRCDIR)/ft_printunsigned.c

OBJS = $(OBJDIR)/ft_printf.o \
       $(OBJDIR)/ft_printnbr.o \
       $(OBJDIR)/ft_printchar.o \
       $(OBJDIR)/ft_printstr.o \
       $(OBJDIR)/ft_printhex.o \
       $(OBJDIR)/ft_printptr.o \
       $(OBJDIR)/ft_printunsigned.o

# Cible par défaut
all: $(NAME)

# Création de la bibliothèque
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "Création de $(NAME) terminée."

# Compilation des fichiers .c en .o
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	$(RM) -r $(OBJDIR)
	@echo "Répertoire $(OBJDIR) supprimé."

# Nettoyage complet
fclean: clean
	$(RM) $(NAME)
	@echo "$(NAME) supprimée."

# Recompilation complète
re: fclean all

# Commandes
.PHONY: all clean fclean re
