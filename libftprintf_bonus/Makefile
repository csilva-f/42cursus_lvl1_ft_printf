# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csilva-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 19:02:20 by csilva-f          #+#    #+#              #
#    Updated: 2022/11/27 19:18:47 by csilva-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
NAMELFT = libft.a

SRCS = ft_printf.c ft_flags.c ft_printf_utils_1.c ft_printf_utils_2.c ft_printf_utils_3.c ft_printf_utils_4.c ft_itoa2.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

bonus: all

$(NAME): $(OBJS) $(LIBFT)
		ar rc $(NAME) $(OBJS)

$(LIBFT):
		${MAKE} -C ./libft

clean:	$(MAKE) clean -C ./libft
		rm -rf $(OBJS)

fclean:	clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re:	fclean all
