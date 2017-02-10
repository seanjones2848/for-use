# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjones <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/02 13:24:08 by sjones            #+#    #+#              #
#    Updated: 2017/02/02 15:33:40 by sjones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = *.c

OBJS = $(SRCS: .c =.o)

FLGS = -Wextra -Werror -Wall

LIBCLN = cd libft

libft:
	$(LIBCLN) && make && make clean

$(NAME): libft
	gcc $(FLGS) -c $(SRCS) -I.
	gcc $(FLGS) $(OBJS) -I.

all: $(NAME)

clean:
	/bin/rm -rf $(OBJS)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean
