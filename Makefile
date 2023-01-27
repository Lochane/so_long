# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 12:43:49 by lsouquie          #+#    #+#              #
#    Updated: 2023/01/27 18:32:06 by lsouquie         ###   ########.fr        #
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
		make -C ./libft
			${CC} ${OBJ} ${PATH_MLX} ${PATH_LIBFT} -o ${NAME} -L ./mlx -lX11 -lXext

clean:
		rm -f ${OBJ}
		make clean -C ${PATH_LIBFT1}
fclean: clean
		rm -f $(NAME)
		make fclean -C ${PATH_LIBFT1}

re: fclean all

.PHONY: all clean fclean re