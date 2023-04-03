MAKEFLAGS += --no-builtin-rules

NAME := push_swap

CC := clang
CFLAGS := -Wall -Wextra -Werror -O2 -MMD -I ./

SOURCES := \
	bubble_sort.c \
	helper.c \
	linked_list.c \
	merge_sort.c \
	operators.c \
	parser.c \
	short_stack_sorter.c \
	stacks/push.c \
	stacks/reverse_rotate.c \
	stacks/rotate.c \
	stacks/swap.c \
	stacks/utils.c \
	main.c
OBJECTS_FOLDER := objs
OBJECTS := $(SOURCES:%.c=objs/%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJECTS): | $(OBJECTS_FOLDER)
$(OBJECTS_FOLDER):
	mkdir -p $@

$(OBJECTS_FOLDER)/%.o: %.c Makefile
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
