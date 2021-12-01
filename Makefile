#---SOURCES---OBJECTS---

SERV		=	server.c

CLIENT  	=	client.c

LIBFT		=	cd libft && make

LIB	  		=	libft/libft.a

SERV_SRC	=	$(SERV)

SERV_OBJ	=	$(SERV_SRC:.c=.o)

CLIENT_SRC  =	$(CLIENT)

CLIENT_OBJ  =	$(CLIENT:.c=.o)

OBJS		=	$(SERV_OBJ) $(CLIENT_OBJ)

#------COMPILATION-----

CC  		=	gcc -Wall -Wextra -Werror

INCLUDE 	=	-I include

SERV_NAME	=	server

CLIENT_NAME =	client

NAME		=	server

#--------COLORS-------

BOLD_PURPLE	=	\033[1;35m

BOLD_CYAN	=	\033[1;36m

BOLD_YELLOW	=	\033[1;33m

NO_COLOR	=	\033[0m

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"

SERV_READY	=	echo "\n📥 Server ready!\n"

CLI_READY	=	echo "\n📟 Client ready!\n"

CLEANED		=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

#--------RULES-------

all: $(NAME)

$(NAME):	 comp_start server client

comp_start:
			@$(COMP_START)
			@$(LIBFT)

server: 	$(SERV_OBJ)
			@$(CC) $(SERV_OBJ) $(LIB) -o $(SERV_NAME)
			@$(SERV_READY)

client: 	$(CLIENT_OBJ)
			@$(CC) $(CLIENT_OBJ) $(LIB) -o $(CLIENT_NAME)
			@$(CLI_READY)

clean:
			@rm -rf $(OBJS)
			@cd libft && make clean
			@$(CLEANED)

fclean:
			@rm -rf $(SERV_NAME) $(CLIENT_NAME)
			@cd libft && make fclean
			@$(FCLEANED)

.c.o:
			@$(CC) $(INCLUDE) -c $< -o ${<:.c=.o}

re:  	fclean all

.PHONY: all minitalk server client clean fclean re libft
