all:
	gcc main.c

norminette:
	norminette ft_printf.c
	norminette ft_printf.h
	norminette main.c