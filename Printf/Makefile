# Nom de la bibliothèque
NAME = libftprintf.a

# Répertoires
SRCDIR = Srcs
INCDIR = Include
OBJDIR = Objs

# Compilateur et options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)

# Commandes
AR = ar rcs
RM = rm -f

# Fichiers sources et objets
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

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
