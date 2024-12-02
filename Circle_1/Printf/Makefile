# Name of the library
NAME = libftprintf.a

# Directories
SRCDIR = Srcs
INCDIR = Includes
OBJDIR = Objs

# Compiler and compilation options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)

# Commands
AR = ar rcs
RM = rm -f

# Source files
SRCS = ft_printf.c \
       ft_printnbr.c \
       ft_printchar.c \
       ft_printstr.c \
       ft_printhex.c \
       ft_printptr.c \
       ft_printunsigned.c

# Add paths to the files
SRC_FILES = $(addprefix $(SRCDIR)/, $(SRCS))
OBJ_FILES = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

# Default target
all: $(NAME)

# Create the library
$(NAME): $(OBJ_FILES)
	$(AR) $(NAME) $(OBJ_FILES)
	@echo "Creation of $(NAME) completed."

# Compile .c files into .o files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	$(RM) -r $(OBJDIR)
	@echo "Directory $(OBJDIR) removed."

# Complete cleanup
fclean: clean
	$(RM) $(NAME)
	@echo "$(NAME) removed."

# Complete recompilation
re: fclean all

# Commands
.PHONY: all clean fclean re
