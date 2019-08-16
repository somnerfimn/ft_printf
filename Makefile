# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oorlov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/31 16:18:23 by oorlov            #+#    #+#              #
#    Updated: 2019/07/31 16:18:25 by oorlov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = a_manager.c \
		buffer_percent.c \
		flag.c \
		ft_itoa_base.c \
		ft_printf.c \
		manager.c \
		n_manager.c \
		properties.c \
		s_manager.c \
		setter.c \
		v_manager.c \
		ft_set_sym.c

LIBSRC = ./libft/*.c

OBJECTS = $(SRC:.c=.o)

LIB = libft.a

HEADS = -I ./includes					\
		-I ./libft						\

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C libft/
	@cp libft/$(LIB) $(NAME)
	@ar rc $(NAME) $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)

%.o : %.c
	@gcc $(FLAGS) $(HEADS) -o $@ -c $?

clean:
	@rm -f $(OBJECTS)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out
	@make fclean -C libft

re: fclean all

