NAME_C = client
NAME_S = server
NAME = minitalk

SRC_DIR = src
OBJ_DIR = objs

SRC_C = $(SRC_DIR)/client.c
SRC_S = $(SRC_DIR)/server.c

OBJ_C = $(OBJ_DIR)/client.o
OBJ_S = $(OBJ_DIR)/server.o

INC_DIR = ./headers

CFLAGS = -I$(INC_DIR)

$(NAME): $(NAME_C) $(NAME_S)

all: $(NAME_C) $(NAME_S)

$(NAME_C): $(OBJ_C)
	$(CC) $^ -o $@

$(NAME_S): $(OBJ_S)
	$(CC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME_C) $(NAME_S)

re: fclean all

.PHONY: all clean fclean re
