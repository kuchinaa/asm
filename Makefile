# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akuchina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/29 14:10:30 by akuchina          #+#    #+#              #
#    Updated: 2019/07/05 11:09:42 by akuchina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= asm_t

SRC		= main.c size.c champion_code.c \
			list_management.c parse.c handle_line.c \
			check_operations.c operation_management.c parse_operations.c \
			arguments.c define_name_comment.c handle_point.c

SRCS	=$(addprefix src/, $(SRC))
OBJS	=$(addprefix obj/, $(SRC:.c=.o))

CFLAGS	= -Wall -Wextra -Werror
CFLAGS	= -I includes/
LFLAGS	= -L ./libft/ -lft

all: $(NAME)

$(NAME):$(OBJS) | lib
	@gcc $(CFLAGS) -o $(NAME) $(LFLAGS) $(OBJS)

obj/%.o: src/%.c | obj
	@$(CC) $(CFLAGS) -o $@ -c $^

re: fclean all

lib:
	@make -C ./libft
	@make clean -C ./libft

clean:
	@rm -rf obj/

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

obj:
	@mkdir obj/

.PHONY: clean fclean re make all
