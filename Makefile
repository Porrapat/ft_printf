


all: libft
	cp ./libft/libft.a libftprintf.a
	gcc -c ft_printf.c -I./libft -L./libft -lft -o ft_printf.o
	ar rcs libftprintf.a ft_printf.o
# gcc main.c ft_printf.c -I./libft -L./libft -lft

run: test
	./a.out

test: libft
	gcc main.c ft_printf.c -I./libft -L./libft -lft

all2: libft
	cp ./libft/libft.a libftprintf.a

norminette:
	norminette ft_printf.c
	norminette ft_printf.h
# norminette main.c

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