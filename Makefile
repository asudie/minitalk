NAME = mimitalk
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): libs server client

libs:
	cd libft && $(MAKE)
	cd my_printf && $(MAKE)

server: server.c
	$(CC) $(CFLAGS) -o server server.c libft/libft.a my_printf/libftprintf.a 

client: client.c
	$(CC) $(CFLAGS) -o client client.c libft/libft.a my_printf/libftprintf.a

clean:
	rm -f server client
	cd libft && $(MAKE) clean
	cd my_printf && $(MAKE) clean

fclean: clean

re: clean all