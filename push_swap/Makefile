NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR)
INCLUDE_DIR = includes
BONUS_DIR = bonus
MANDATORY_DIR = manda

HEADERS = $(INCLUDE_DIR)/push_swap.h $(INCLUDE_DIR)/get_next_line.h $(INCLUDE_DIR)/checker.h $(INCLUDE_DIR)/libft.h

MANDATORY_SRCS = $(MANDATORY_DIR)/main.c $(MANDATORY_DIR)/linked_list_utils.c $(MANDATORY_DIR)/push.c \
                 $(MANDATORY_DIR)/swap.c $(MANDATORY_DIR)/reverse.c $(MANDATORY_DIR)/rreverse.c \
                 $(MANDATORY_DIR)/check_erros.c $(MANDATORY_DIR)/intel_sort.c $(MANDATORY_DIR)/intel_sort_utils.c \
                 $(MANDATORY_DIR)/check_sorted.c $(MANDATORY_DIR)/check_sorted_2.c

BONUS_SRCS = $(BONUS_DIR)/checker.c $(BONUS_DIR)/checker_tools.c \
             $(BONUS_DIR)/get_next_line.c $(BONUS_DIR)/get_next_line_utils.c \
             $(MANDATORY_DIR)/linked_list_utils.c $(MANDATORY_DIR)/check_erros.c $(MANDATORY_DIR)/push.c \
             $(MANDATORY_DIR)/swap.c $(MANDATORY_DIR)/reverse.c $(MANDATORY_DIR)/rreverse.c $(MANDATORY_DIR)/intel_sort_utils.c \
             $(MANDATORY_DIR)/intel_sort.c $(MANDATORY_DIR)/check_sorted.c $(MANDATORY_DIR)/check_sorted_2.c
			 
LIBFT = libft/libft.a

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(MANDATORY_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re