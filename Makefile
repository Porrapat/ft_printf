all: libft
	cp ./libft/libft.a libftprintf.a
	gcc -c -Wall -Wextra -Werror ft_printf.c -I./libft -L./libft -lft -o ft_printf.o
	gcc -c -Wall -Wextra -Werror ft_printf_print_char.c  -I./libft -L./libft -lft -o ft_printf_print_char.o
	gcc -c -Wall -Wextra -Werror ft_printf_print_string.c  -I./libft -L./libft -lft -o ft_printf_print_string.o
	gcc -c -Wall -Wextra -Werror ft_printf_print_percent.c  -I./libft -L./libft -lft -o ft_printf_print_percent.o
	gcc -c -Wall -Wextra -Werror ft_printf_print_decimal.c  -I./libft -L./libft -lft -o ft_printf_print_decimal.o
	gcc -c -Wall -Wextra -Werror ft_printf_print_hexadecimal.c  -I./libft -L./libft -lft -o ft_printf_print_hexadecimal.o
	gcc -c -Wall -Wextra -Werror ft_printf_print_unsigned.c  -I./libft -L./libft -lft -o ft_printf_print_unsigned.o
	gcc -c -Wall -Wextra -Werror ft_printf_print_pointer.c  -I./libft -L./libft -lft -o ft_printf_print_pointer.o
	ar rcs libftprintf.a ft_printf.o ft_printf_print_char.o ft_printf_print_string.o ft_printf_print_percent.o ft_printf_print_decimal.o ft_printf_print_hexadecimal.o ft_printf_print_unsigned.o ft_printf_print_pointer.o
	gcc -Wall -Wextra -Werror main.c -I./libft -L. -lftprintf

debug: libft
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

test: libft
	gcc main.c ft_printf.c -I./libft -L./libft -lft

all2: libft
	cp ./libft/libft.a libftprintf.a

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
	
clean:
	make -C ./libft clean
	make -C ./libft fclean
	rm -rf *.o

fclean:	clean
	rm -rf libftprintf.a
	rm -rf a.out

libft:
	make -C ./libft

fcleanlibft:
	make -C ./libft fclean

.PHONY: libft all norminette clean fclean re bonus