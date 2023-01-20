## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: afelipe- <afelipe->                        +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2023/01/19 07:52:28 by afelipe-          #+#    #+#             ##
##   Updated: 2023/01/19 16:02:50 by afelipe-         ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME_C = client
NAME_S = server
NAME_CBONUS = client_bonus
NAME_SBONUS = server_bonus

NAME = minitalk
NAMEB = minitalk_bonus

SRC_DIR = src
OBJ_DIR = objs

SRC_C = src/client.c
SRC_CB = src/client_bonus.c
SRC_S = src/server.c
SRC_SB = src/server_bonus.c


OBJ_C = objs/client.o
OBJ_CB = objs/client_bonus.o
OBJ_S = objs/server.o
OBJ_SB = objs/server_bonus.o

LIBFT_LIB = ./libft/libft.a
PRINTF_LIB = ./printf/libftprintf.a

INC_DIR = ./headers

CFLAGS = -I$(INC_DIR)

$(NAME): $(NAME_C) $(NAME_S)
$(NAMEB): $(NAME_CBONUS) $(NAME_SBONUS)

all: $(NAME_C) $(NAME_S)
bonus: $(NAME_CBONUS) $(NAME_SBONUS)

$(NAME_C): $(OBJ_C)
	make re -C ./printf/
	make re -C ./libft/
	rm -rf client_bonus
	cc -g $(CFLAGS) $(OBJ_C) $(LIBFT_LIB) $(PRINTF_LIB) -o $(NAME_C)

$(NAME_S): $(OBJ_S)
	make re -C ./printf/
	make re -C ./libft/
	rm -rf server_bonus
	cc -g $(CFLAGS) $(OBJ_S) $(LIBFT_LIB) $(PRINTF_LIB) -o $(NAME_S)

$(NAME_CBONUS): $(OBJ_CB)
	make re -C ./printf/
	make re -C ./libft/
	rm -rf client
	cc -g $(CFLAGS) $(OBJ_CB) $(LIBFT_LIB) $(PRINTF_LIB) -o $(NAME_CBONUS)

$(NAME_SBONUS): $(OBJ_SB)
	make re -C ./printf/
	make re -C ./libft/
	rm -rf server
	cc -g $(CFLAGS) $(OBJ_SB) $(LIBFT_LIB) $(PRINTF_LIB) -o $(NAME_SBONUS)
objs/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME_C) $(NAME_S)
	@rm -f $(NAME_CBONUS) $(NAME_SBONUS)
	make fclean -C ./printf/
	make fclean -C ./libft/

re: fclean all

.PHONY: all clean fclean re
