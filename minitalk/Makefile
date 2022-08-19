SERVER			:=	server

CLIENT			:=	client

SRCS :=	minitalk_utils.c

OBJ := $(SRCS:%.c=%.o)

CC			:=	@gcc
CFLAGS		:= 	-Wall -Werror -Wextra

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ) server.o
	@make -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJ) server.o ./ft_printf/libftprintf.a -o $(SERVER)
	@printf "[\e[36mSUCCESS\e[0m] server ready\n"

$(CLIENT): $(OBJ) client.o
	$(CC) $(CFLAGS) $(OBJ) client.o ./ft_printf/libftprintf.a -o $(CLIENT)
	@printf "[\e[36mSUCCESS\e[0m] client ready\n"

fclean : clean
	@rm -rf $(SERVER) $(CLIENT)
	@make -C ./ft_printf fclean

clean :
	@rm -rf *.o
	@rm -rf server client
	@make -C ./ft_printf clean

re : fclean all

.PHONY: all fclean re clean
