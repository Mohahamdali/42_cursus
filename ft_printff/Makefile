NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_printf_tools.c
OBJ = $(SRC:.c=.o)
HEADER = ft_printf.h


all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
