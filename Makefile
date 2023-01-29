# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lochane <lochane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 12:43:49 by lsouquie          #+#    #+#              #
#    Updated: 2023/01/28 23:51:17 by lochane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC =  $(addprefix src/, main_map map map_utils map_utils2 algo_map so_long rendering events gameplay)


OBJ = $(addsuffix .o, ${SRC})
CC = cc
FLAGS = -Wall -Werror -Wextra -g3
HEADER = .
PATH_MLX = ./Minilibx/libmlx.a
PATH_LIBFT = ./libft/libft.a

all: $(NAME)

%.o:%.c
		${CC} ${FLAGS} -c $< -o $@ -I${HEADER}

$(NAME): ${OBJ}
#			@echo "			-> Compiling $(NAME)"
			@make -C ./libft
			${CC} ${OBJ} ${PATH_MLX} ${PATH_LIBFT} -o ${NAME} -L ./mlx -lX11 -lXext
#			@echo "			-> Compiled"

clean:
		rm -f ${OBJ}
		make clean -C ./libft
fclean: clean
		rm -f $(NAME)
		make fclean -C ./libft

re: fclean all

norme:
		norminette src/*.c include/*.h
		

.PHONY: all clean fclean re