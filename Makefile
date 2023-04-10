# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 12:43:49 by lsouquie          #+#    #+#              #
#    Updated: 2023/03/27 11:52:53 by lsouquie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC =  $(addprefix src/, main_map map map_utils map_utils2 algo_map so_long rendering events gameplay)
INC = $(addprefix include/, struct.h so_long.h)

OBJ = $(addsuffix .o, ${SRC})
CC = cc
FLAGS = -Wall -Werror -Wextra -g3
HEADER = .
PATH_MLX = ./Minilibx/libmlx.a
PATH_LIBFT = ./libft/libft.a

all: $(NAME)

%.o:%.c
		@${CC} ${FLAGS} -c $< -o $@ -I${HEADER}

$(NAME): ${OBJ}
			@echo "			-> Compiling $(NAME)"
			@make -C ./libft
			@make -C ./Minilibx
			@${CC} ${OBJ} ${PATH_MLX} ${PATH_LIBFT} -o ${NAME} -L ./mlx -lX11 -lXext
			@echo "			-> Compiled"

clean:
		@rm -f ${OBJ}
		@make clean -C ./libft
fclean: clean
		@rm -f $(NAME)
		@make clean -C ./Minilibx
		@make fclean -C ./libft

re: fclean all

norme:
		norminette $(OBJ).c $(INC)
		

.PHONY: all clean fclean re