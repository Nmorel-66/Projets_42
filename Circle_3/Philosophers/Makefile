NAME = philo

# OS detection
OS = $(shell uname)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FLAGS = -lpthread

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

# Files
SRC_FILES = \
	$(SRC_DIR)/philo.c \
	$(SRC_DIR)/philo_init.c \
	$(SRC_DIR)/philo_actions.c \
	$(SRC_DIR)/philo_monitor.c \
	$(SRC_DIR)/philo_utils.c
	
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
all: $(NAME)


# Create the executable
$(NAME): $(OBJ_FILES)
	@echo "$(COLOR_BLUE)Linking object files to create the executable $(NAME)...$(COLOR_RESET)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(FLAGS)
	@echo "$(COLOR_GREEN)Executable $(NAME) created successfully!$(COLOR_RESET)"

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(COLOR_YELLOW)Compiling $< to $@...$(COLOR_RESET)"
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "$(COLOR_GREEN)$< compiled successfully.$(COLOR_RESET)"

# Debug target
debug:
	$(MAKE) CFLAGS="$(CFLAGS) -g" re
	
# Clean object files
clean:
	@echo "$(COLOR_RED)Cleaning object files...$(COLOR_RESET)"
	rm -rf $(OBJ_DIR)
	@echo "$(COLOR_YELLOW)Cleaning MiniLibX...$(COLOR_RESET)"
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
