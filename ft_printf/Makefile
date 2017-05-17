.phony: all re clean fclean

NAME = ft_printf

SRC_PATH = ./src
SRC_NAME =	main.c

OBJ_PATH = ./obj
OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH = ./inc
INC_NAME =	ft_printf.h	\
		libft.h

LIB_PATH = ./lib
LIB_NAME = libft.a

SRC = $(addprefix &(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix &(OBJ_PATH)/, $(OBJ_NAME))
INC = $(addprefix &(INC_PATH)/, $(INC_NAME))
LIB = $(addprefix &(LIB_PATH)/, $(LIB_NAME))

FLAGS = -Wall -Werror Wextra

all: $(NAME)

NAME:
	gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
