# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjones <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/02 13:24:08 by sjones            #+#    #+#              #
#    Updated: 2017/02/15 00:51:02 by sjones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = *.c

OBJS = *.o

FLGS = -Wextra -Werror -Wall -g

LIBCLN = cd libft/

$(NAME):
	$(LIBCLN) && make && make clean
	gcc $(FLGS) $(SRCS) -o $(NAME) libft/libft.a

all: $(NAME)

clean:
	/bin/rm -rf $(OBJS)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean
