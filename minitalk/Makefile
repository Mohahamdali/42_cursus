CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

SERVER_SRC = server.c ft_putnbr_fd.c
CLIENT_SRC = client.c ft_atoi.c ft_putstr_fd.c 
HEADER = minitalk.h

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJ)
	$(CC) $(SERVER_OBJ) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CLIENT_OBJ) -o $(CLIENT)

$(SERVER_OBJ): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT_OBJ): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
