NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
OBJ_DIR = obj/

# Source files
SRC_FILES = main.c \
	operations/push.c \
	operations/swap.c \
	operations/rotate.c \
	operations/reverse.c \
	stack/stack_init.c \
	stack/stack_utils.c \
	stack/stack_free.c \
	algorithm/sort_small.c \
	algorithm/turk_sort.c \
	utils/error.c \
	utils/utils.c

# Convert source files to full paths
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

# Create object files list
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Create object file directories
OBJ_DIRS = $(sort $(dir $(OBJ)))

all: $(NAME)

# Create object directories and compile
$(NAME): $(OBJ_DIRS) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Create necessary directories for object files
$(OBJ_DIRS):
	mkdir -p $@

# Compile source files to object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
