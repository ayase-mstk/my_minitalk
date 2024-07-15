NAME = minitalk
CLIANT_NAME  = client
SERVER_NAME  = server
CLIENT_BONUS_NAME = client_bonus
SERVER_BONUS_NAME = server_bonus

SRC_DIR = ./src
C_SRCS = $(SRC_DIR)/client.c
S_SRCS = $(SRC_DIR)/server.c
C_OBJS = $(C_SRCS:%.c=%.o)
S_OBJS = $(S_SRCS:%.c=%.o)

C_BONUS_SRCS = $(SRC_DIR)/client_bonus.c
S_BONUS_SRCS = $(SRC_DIR)/server_bonus.c
C_BONUS_OBJS = $(C_BONUS_SRCS:%.c=%.o)
S_BONUS_OBJS = $(S_BONUS_SRCS:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INC_DIR = ./include
INCLUDE = -I$(INC_DIR)
LIBFT_DIR = ./libft
PRINTF_DIR = ./libftprintf
LIBS = -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lftprintf -lft

all: $(NAME)

$(NAME): $(CLIANT_NAME) $(SERVER_NAME)

$(CLIANT_NAME): $(C_OBJS)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -o $(CLIANT_NAME) $(INCLUDE) $(C_OBJS) $(LIBS)

$(SERVER_NAME): $(S_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(INCLUDE) $(S_OBJS) $(LIBS)

bonus: $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

$(CLIENT_BONUS_NAME): $(C_BONUS_OBJS)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS_NAME) $(INCLUDE) $(C_BONUS_OBJS) $(LIBS)

$(SERVER_BONUS_NAME): $(S_BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER_BONUS_NAME) $(INCLUDE) $(S_BONUS_OBJS) $(LIBS)

.c.o :
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

bonus:
	make allbonus

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	$(RM) $(C_OBJS) $(S_OBJS) $(C_BONUS_OBJS) $(S_BONUS_OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	$(RM) $(NAME) $(CLIANT_NAME) $(SERVER_NAME) $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re