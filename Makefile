NAME = minitalk
CLIANT_NAME  = client
SERVER_NAME  = server

C_SRCS = client.c
S_SRCS = server.c
C_OBJS = $(C_SRCS:%.c=%.o)
S_OBJS = $(S_SRCS:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT_DIR = ./libft
PRINTF_DIR = ./libftprintf
LIBS = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

all: $(NAME)

$(NAME): $(CLIANT_NAME) $(SERVER_NAME)

$(CLIANT_NAME): $(C_OBJS)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -o $(CLIANT_NAME) $(C_OBJS) $(LIBS)

$(SERVER_NAME): $(S_OBJS)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(S_OBJS) $(LIBS)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	$(RM) $(C_OBJS) $(S_OBJS)

fclean: clean
	$(RM) $(CLIANT_NAME) $(SERVER_NAME) $(NAME)

re: fclean all

.PHONY: all clean fclean re