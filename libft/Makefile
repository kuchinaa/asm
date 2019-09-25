# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akuchina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 11:21:28 by akuchina          #+#    #+#              #
#    Updated: 2019/01/25 19:03:16 by akuchina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	additional.c flag_minus.c ft_atoi.c ft_bzero.c ft_intlen.c \
		ft_intswap.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_itoa.c ft_itoa_base.c ft_list_find.c ft_lstadd.c \
		ft_lstdel.c ft_lstdelone.c ft_lstfree.c ft_lstiter.c ft_lstmap.c \
		ft_lstnew.c ft_lstpush.c ft_lstrev.c ft_lstsize.c ft_memalloc.c \
		ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
		ft_memmove.c ft_memset.c ft_nbwords.c ft_printf.c ft_putchar.c \
		ft_putchar_fd.c ft_putdouble.c ft_putendl.c ft_putendl_fd.c \
		ft_putlonglong.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
		ft_putstr_fd.c ft_strcat.c ft_strcheck.c ft_strchr.c ft_strclr.c \
		ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strduplen.c \
		ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
		ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
		ft_strncpy.c ft_strndup.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
		ft_strrchr.c ft_strrev.c ft_strskip.c ft_strsplit.c ft_strstr.c \
		ft_strsub.c ft_strtrim.c ft_swap.c ft_tolower.c ft_toupper.c \
		get_next_line.c get_value.c octa.c output.c print_structure.c \
		small_output.c structure.c

OBJ = $(SRC:.c=.o)

DEL = @rm -f

FLAG = -Wall -Werror -Wextra -I includes

all: $(NAME)

$(NAME):
	@gcc -c $(FLAG) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@$(DEL) $(OBJ)

fclean: clean
	@$(DEL) $(NAME)

re: fclean all

.PHONY: all clean fclean re
