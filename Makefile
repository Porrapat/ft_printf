all:
	gcc main.c

norminette:
	norminette ft_printf.c
	norminette main.c