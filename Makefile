CC	= gcc -Wextra -Werror -Wall

all	:
		@$(CC) server.c libft/libft.a -o server
		@$(CC) client.c libft/libft.a -o client
