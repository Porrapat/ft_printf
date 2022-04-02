# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 09:51:37 by ppetchda          #+#    #+#              #
#    Updated: 2022/03/31 10:21:42 by ppetchda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c \
		ft_printf_print_char.c \
		ft_printf_print_string.c \
		ft_printf_print_percent.c \
		ft_printf_print_decimal.c \
		ft_printf_print_hexadecimal.c \
		ft_printf_print_unsigned.c \
		ft_printf_print_pointer.c \
		ft_printf_utils.c \
		ft_printf_utils_2.c

OBJS = $(SRCS:.c=.o)

NAME		= libftprintf.a
LIBFT		= libft
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):	libft $(OBJS)
			make -C $(LIBFT)
			cp libft/libft.a .
			mv libft.a $(NAME)
			ar rcs $(NAME) $(OBJS)
			rm -rf $(OBJS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ -Ilibft -I.

clean:
	rm -rf $(OBJS)
	make -C ./libft clean

fclean:	clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT)

re:	fclean all

bonus: all

rebonus: fclean bonus

libft:
	make -C ./libft

fcleanlibft:
	make -C ./libft fclean

.PHONY: libft all norminette clean fclean re bonus rebonus debug run
