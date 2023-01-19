## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: afelipe- <afelipe->                        +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2023/01/19 07:52:28 by afelipe-          #+#    #+#             ##
##   Updated: 2023/01/19 07:52:48 by afelipe-         ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME_C = client
NAME_S = server
NAME = minitalk

SRC_DIR = src
OBJ_DIR = objs

SRC_C = src/client.c
SRC_S = src/server.c

OBJ_C = objs/client.o
OBJ_S = objs/server.o

LIBFT_LIB = ./libft/libft.a
PRINTF_LIB = ./printf/libftprintf.a

INC_DIR = ./headers

CFLAGS = -I$(INC_DIR)

$(NAME): $(NAME_C) $(NAME_S)

all: $(NAME_C) $(NAME_S)

$(NAME_C): $(OBJ_C)
	make re -C ./printf/
	make re -C ./libft/
	cc -g $(CFLAGS) $(OBJ_C) $(LIBFT_LIB) $(PRINTF_LIB) -o $(NAME_C)

$(NAME_S): $(OBJ_S)
	make re -C ./printf/
	make re -C ./libft/
	cc -g $(CFLAGS) $(OBJ_S) $(LIBFT_LIB) $(PRINTF_LIB) -o $(NAME_S)

objs/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME_C) $(NAME_S)
	make fclean -C ./printf/
	make fclean -C ./libft/

re: fclean all

.PHONY: all clean fclean re
