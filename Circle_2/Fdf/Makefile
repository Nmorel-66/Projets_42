NAME = fdf

# OS detection
OS = $(shell uname)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = Libft
LIBFT_OBJ_DIR = $(LIBFT_DIR)/obj

# MiniLibX
ifeq ($(OS), Darwin)  # macOS
    MLX_DIR = minilibx_macos
    MLX_LIB = $(MLX_DIR)/libmlx.a
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else  # Linux
    MLX_DIR = minilibx-linux
    MLX_LIB = $(MLX_DIR)/libmlx.a
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lz
endif

# Files
SRC_FILES = \
	$(SRC_DIR)/fdf.c \
	$(SRC_DIR)/hook.c \
	$(SRC_DIR)/read.c \
	$(SRC_DIR)/draw.c \
	$(SRC_DIR)/init.c \
	$(SRC_DIR)/move.c \
	$(SRC_DIR)/events.c \
	$(SRC_DIR)/color.c \
	$(SRC_DIR)/menu.c


# Libft files
LIBFT_SRC = \
	$(LIBFT_DIR)/ft_putstr_fd.c \
	$(LIBFT_DIR)/ft_split.c \
	$(LIBFT_DIR)/ft_strlen.c \
	$(LIBFT_DIR)/ft_strncmp.c \
	$(LIBFT_DIR)/ft_strjoin.c \
	$(LIBFT_DIR)/ft_atoi.c \
	$(LIBFT_DIR)/ft_strchr.c \
	$(LIBFT_DIR)/ft_strdup.c \
	$(LIBFT_DIR)/get_next_line.c

LIBFT_OBJ = $(LIBFT_SRC:$(LIBFT_DIR)/%.c=$(LIBFT_OBJ_DIR)/%.o)

# Object files
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Colors for echo
COLOR_RESET = \033[0m
COLOR_GREEN = \033[32m
COLOR_RED = \033[31m
COLOR_YELLOW = \033[33m
COLOR_BLUE = \033[34m
COLOR_CYAN = \033[36m

# Targets
all: $(MLX_LIB) $(NAME)

# Compile MiniLibX if not built
$(MLX_LIB):
	@echo "$(COLOR_CYAN)Compiling MiniLibX...$(COLOR_RESET)"
	@make -C $(MLX_DIR)

# Create the executable
$(NAME): $(OBJ_FILES) $(LIBFT_OBJ) $(MLX_LIB)
	@echo "$(COLOR_BLUE)Linking object files to create the executable $(NAME)...$(COLOR_RESET)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LIBFT_OBJ) $(MLX_FLAGS)
	@echo "$(COLOR_GREEN)Executable $(NAME) created successfully!$(COLOR_RESET)"

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(COLOR_YELLOW)Compiling $< to $@...$(COLOR_RESET)"
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "$(COLOR_GREEN)$< compiled successfully.$(COLOR_RESET)"

# Compile libft source files to object files
$(LIBFT_OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c
	@echo "$(COLOR_YELLOW)Compiling libft $< to $@...$(COLOR_RESET)"
	@mkdir -p $(LIBFT_OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -c $< -o $@
	@echo "$(COLOR_GREEN)$< compiled successfully.$(COLOR_RESET)"

# Clean object files
clean:
	@echo "$(COLOR_RED)Cleaning object files...$(COLOR_RESET)"
	rm -rf $(OBJ_DIR) $(LIBFT_OBJ_DIR)
	@echo "$(COLOR_GREEN)Object files cleaned successfully!$(COLOR_RESET)"

# Remove executable
fclean: clean
	@echo "$(COLOR_RED)Removing executable $(NAME)...$(COLOR_RESET)"
	rm -f $(NAME)
	@echo "$(COLOR_GREEN)Executable $(NAME) removed successfully!$(COLOR_RESET)"

# Rebuild the project
re: fclean all

# Phony targets to avoid name conflicts
.PHONY: all clean fclean re
