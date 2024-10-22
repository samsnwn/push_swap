NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS_DIR = src
OBJS_DIR = obj
INCS_DIR = include

HEAD = push_swap.h
SRCS = $(SRCS_DIR)/main.c $(SRCS_DIR)/push_swap.c
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
clean:
	$(RM) -r $(OBJS_DIR)
 
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
