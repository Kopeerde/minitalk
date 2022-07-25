
NAME_C = client
NAME_H = server

FLAGS = -Wall -Wextra -Werror -g3 -gdwarf-4

SRC_C = ./src/client/main.c

LIB_C = ./src/lib/libft/libft.a

SRC_H = ./src/host/main.c ./src/host/host_utils.c

LIB_H = ./src/lib/libft/libft.a

all: $(NAME_C) $(NAME_H)

$(NAME_C):
	cd ./src/lib/libft && make
	clang $(FLAGS) $(SRC_C) $(LIB_C) -o $(NAME_C)

$(NAME_H):
	cd ./src/lib/libft && make
	clang $(FLAGS) $(SRC_H) $(LIB_H) -o $(NAME_H)

clean:
	cd ./src/lib/libft && make clean
	rm -f ./src/client/*.o
	rm -f ./src/host/*.o

fclean: clean
	cd ./src/lib/libft && make fclean
	rm -f client
	rm -f server

re: fclean
	make