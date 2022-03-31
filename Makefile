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
		ft_printf_print_pointer.c 

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

norminette:
	norminette ft_printf.c
	norminette ft_printf_print_char.c
	norminette ft_printf_print_string.c
	norminette ft_printf_print_percent.c
	norminette ft_printf_print_decimal.c
	norminette ft_printf_print_hexadecimal.c
	norminette ft_printf_print_pointer.c
	norminette ft_printf_print_unsigned.c
	norminette ft_printf.h

debug: libft $(SRCS)
	gcc -g -c -Wall -Wextra -Werror ft_printf.c -I./libft -L./libft -lft -o ft_printf.o
	gcc -g -c -Wall -Wextra -Werror ft_printf_print_char.c  -I./libft -L./libft -lft -o ft_printf_print_char.o
	gcc -g -c -Wall -Wextra -Werror ft_printf_print_string.c  -I./libft -L./libft -lft -o ft_printf_print_string.o
	gcc -g -c -Wall -Wextra -Werror ft_printf_print_percent.c  -I./libft -L./libft -lft -o ft_printf_print_percent.o
	gcc -g -c -Wall -Wextra -Werror ft_printf_print_decimal.c  -I./libft -L./libft -lft -o ft_printf_print_decimal.o
	gcc -g -c -Wall -Wextra -Werror ft_printf_print_hexadecimal.c  -I./libft -L./libft -lft -o ft_printf_print_hexadecimal.o
	gcc -g -c -Wall -Wextra -Werror ft_printf_print_unsigned.c  -I./libft -L./libft -lft -o ft_printf_print_unsigned.o
	gcc -g -c -Wall -Wextra -Werror ft_printf_print_pointer.c  -I./libft -L./libft -lft -o ft_printf_print_pointer.o
	gcc -g -Wall -Wextra -Werror ft_printf.o ft_printf_print_char.o ft_printf_print_string.o \
		ft_printf_print_percent.o ft_printf_print_decimal.o \
		ft_printf_print_hexadecimal.o ft_printf_print_unsigned.o \
		ft_printf_print_pointer.o \
		main.c -I./libft -L./libft -lft

run: all
	./a.out