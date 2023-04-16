# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lochane <lochane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 12:43:49 by lsouquie          #+#    #+#              #
#    Updated: 2023/04/16 01:52:37 by lochane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCDIR = src/
OBJDIR = obj/
MLXPATH = ./Minilibx/libmlx.a
LIBPATH = ./libft/libft


SRC =  $(SRCDIR)map.c $(SRCDIR)utils.c \
		$(SRCDIR)utils2.c $(SRCDIR)algo_map.c $(SRCDIR)so_long.c \
		$(SRCDIR)rendering.c $(SRCDIR)events.c $(SRCDIR)gameplay.c \
		$(SRCDIR)load.c $(SRCDIR)enemy.c\


OBJ = $(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRC))
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
HEADER = .

all: $(NAME)


$(NAME): $(OBJ) | lib
		@echo "			-> Compiling $(NAME)..."
		@make -C ./Minilibx
		@${CC} ${OBJ} ${MLXPATH} ${LIBPATH} -o ${NAME} -L ./mlx -lX11 -lXext
		@echo "			-> Compiling $(NAME)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	
$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

lib:
	@make -C ./libft

clean:
	@rm -rf $(OBJDIR)
	@make clean -C ./libft

fclean: clean
		@rm -f $(NAME)
		@make fclean -C ./libft
		@make clean -C ./Minilibx
		
re: fclean all

.PHONY: all lib clean fclean re