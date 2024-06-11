CC = gcc
# CFLAGS = -Wall -Wextra -Werror

all: server client

server: server.c
	$(CC) $(CFLAGS) -g -o server server.c

client: client.c
	$(CC) $(CFLAGS) -g -o client client.c

clean:
	rm -f server client

re: clean all