run:
	gcc main.c

all: libft
	cp ./libft/libft.a libftprintf.a

norminette:
	norminette ft_printf.c
	norminette ft_printf.h
	norminette main.c

clean:
	rm -rf *.o

fclean:	clean
	rm -rf libftprintf.a

libft:
	make -C ./libft

fcleanlibft:
	make -C ./libft fclean

.PHONY: libft all norminette clean fclean re bonus