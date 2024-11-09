NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
OBJ_DIR = obj/

SRCS = src/main.c \
       src/operations/push.c \
       src/operations/swap.c \
       src/operations/rotate.c \
       src/operations/reverse.c \
       src/stack/stack_init.c \
       src/stack/stack_utils.c \
       src/stack/stack_free.c \
       src/algorithm/sort_small.c \
       src/algorithm/turk_sort.c \
       src/utils/error.c \
       src/utils/utils.c

OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
