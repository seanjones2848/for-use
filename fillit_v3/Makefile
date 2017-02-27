# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjones <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/02 13:24:08 by sjones            #+#    #+#              #
#    Updated: 2017/02/26 16:41:46 by sjones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS =	ft_list_push_back.c	\
		ft_lstlen.c			\
		ft_mkbrd.c			\
		ft_newtet.c			\
		ft_read.c			\
		ft_sqrtr.c			\
		main.c				\
		minbrdsize.c		\
		solver.c			\
		trim.c				\
		validate.c			\
		set_l.c

OBJS = $(SOURCE:.c=.o)

FLGS = -Wextra -Werror -Wall

LIBCLN = cd libft/

$(NAME):
	$(LIBCLN) && make
	gcc $(FLGS) $(SRCS) -o $(NAME) libft/libft.a
	cd ..

all: $(NAME)

clean:
	$(LIBCLN) && make clean
	cd ..
	rm -f $(OBJS)

fclean: clean
	/bin/rm -rf $(NAME)
	$(LIBCLN) && make fclean

re: fclean all 

.PHONY: all re clean fclean
