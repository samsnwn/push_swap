NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS_DIR = src
OBJS_DIR = obj
INCS_DIR = include

LIBFT = libft/libft.a

HEAD = push_swap.h
SRCS = $(SRCS_DIR)/main.c \
       $(SRCS_DIR)/parse.c \
       $(SRCS_DIR)/sort.c \
       $(SRCS_DIR)/free.c \
       $(SRCS_DIR)/errors.c \
       $(SRCS_DIR)/utils.c \
       $(SRCS_DIR)/complex_sort.c \
       $(SRCS_DIR)/complex_sort2.c \
       $(SRCS_DIR)/node_utils.c \
       $(SRCS_DIR)/swap.c \
       $(SRCS_DIR)/push.c \
       $(SRCS_DIR)/rotate.c \
       $(SRCS_DIR)/reverse_rotate.c \

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)
	
clean:
	$(RM) -r $(OBJS_DIR)
	make -C libft clean
 
fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
