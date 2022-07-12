# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmendes- <kmendes-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 09:48:58 by kmendes-          #+#    #+#              #
#    Updated: 2022/06/15 13:49:57 by kmendes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strlen.c  ft_memset.c           \
	  ft_strnstr.c ft_atoi.c ft_calloc.c \
	  ft_strjoin.c ft_itoa.c ft_putstr_fd.c \
	  ft_printf.c   \
	  ft_strjoin_char.c      ft_itoa_overflow.c \
	  ft_strjoin_free_both.c ft_convert_base.c  \
	  ft_parse_pointer_string.c ft_strjoin_string.c ft_strchr.c

FLAGS = -Wall -Wextra -Werror -g -gdwarf-4

all: $(NAME)

$(NAME):
	clang $(FLAGS) -c $(SRC)
	ar rc $(NAME) *.o

clean:
	rm -f *.o *.h.gch

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

bonus: $(NAME)
	gcc $(FLAGS) -c $(BONUS_SRC)
	ar rc $(NAME) *.o
