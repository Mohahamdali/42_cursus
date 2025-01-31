# -*- Makefile dyal manda -*-


NAME = push_swap
SRCS =  main.c linked_list_utils.c push.c swap.c reverse.c rreverse.c \
 check_erros.c quick_sort.c merge.c
CC 	 = cc
CFLAGS =
LIBFT = ../libft/libft.a
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c 
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
fclean : clean
	@rm -f $(NAME)

re: fclean all