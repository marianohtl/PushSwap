MAKEFLAGS += --no-builtin-rules

NAME := push_swap

CC := clang
CFLAGS := -Wall -Wextra -Werror -g3 -MMD

SOURCES := \
	main.c
OBJECTS_FOLDER := objs
OBJECTS := $(SOURCES:%.c=objs/%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJECTS_FOLDER):
	mkdir -p $@

$(OBJECTS_FOLDER)/%.o: %.c $(OBJECTS_FOLDER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
