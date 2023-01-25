# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 12:43:49 by lsouquie          #+#    #+#              #
#    Updated: 2023/01/25 18:18:35 by lsouquie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

SRC = main_map \
		map \
		map_utils \
		map_utils2 \
		algo_map \
		so_long \
		rendering \
		events \
		gameplay \

OBJ = $(addsuffix .o, ${SRC})
CC = cc
FLAGS = -Wall -Werror -Wextra -g3
HEADER = .
PATH_MLX1 = Minilibx
PATH_LIBFT1 = libft/
PATH_MLX = ./Minilibx/libmlx.a
PATH_LIBFT = ./libft/libft.a

all: $(NAME)

%.o:%.c
		${CC} ${FLAGS} -c $< -o $@ -I${HEADER}
mlx:
		make -C ${PATH_MLX1}

${PATH_LIBFT}libft.a:
		make all -C ${PATH_LIBFT1}

$(NAME): ${PATH_LIBFT}libft.a ${OBJ}
		cp ${PATH_LIBFT1}libft.a ./${NAME}
		ar rcs ${NAME} ${OBJ}
			${CC} ${OBJ} ${PATH_MLX} ${PATH_LIBFT} -o ${NAME} -L ./mlx -lX11 -lXext
		mv $(OBJ) ./obj


clean:
		rm -f ${OBJ}
		make fclean -C ${PATH_LIBFT1}
fclean: clean
		rm -f $(NAME)
		make fclean -C ${PATH_LIBFT1}

re: fclean all

.PHONY: all clean fclean re