NAME = so_long

SRCS = manda/button.c manda/check_line_player.c manda/check_walls.c manda/clear.c manda/draw_map_utils.c manda/draw_map.c manda/flood_fill.c manda/main.c manda/move_player.c manda/parsing_map.c \
get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ft_printf/ft_printf.c ft_printf/ft_printf_tools.c manda/clear_2.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

HEADERS = includes/get_next_line.h includes/so_long.h includes/ft_printf.h
LIBFT_HEADERS = Libft/includes/libft.h

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

LIBRARY = Libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBRARY)
	$(CC) $(OBJS) -o $(NAME) $(LIBRARY) $(MLX_FLAGS)

%.o: %.c $(HEADERS) $(LIBFT_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBRARY):
	make -C Libft

clean:
	@rm -f $(OBJS)
	@make -C Libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C Libft fclean

re: fclean all

.PHONY: all clean fclean re
