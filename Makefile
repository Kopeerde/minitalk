
NAME_C = client
NAME_H = host

FLAGS = -Wall -Wextra -Werror -g3 -gdwarf-4

SRC_C = ./src/client/main.c

SRC_H = ./src/host/main.c

all: $(NAME_C) $(NAME_H)

$(NAME_C):
	clang $(FLAGS) $(SRC_C) -o $(NAME_C)

$(NAME_H):
	clang $(FLAGS) $(SRC_H) -o $(NAME_H)

clean:
	rm -f ./src/client/*.o
	rm -f ./src/host/*.o

fclean: clean
	rm -f client
	rm -f host

re: fclean
	make