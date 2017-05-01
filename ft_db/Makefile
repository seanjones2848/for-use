.PHONY: all re clean fclean

NAME = ft_db

SRC_PATH = ./src
INC_PATH = ./headers
OBJ_PATH = ./obj

SRC_NAME = ft_db.c
INC_NAME = ft_db.h
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME)) 
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -o $(SRC)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf ft_

re: fclean all
