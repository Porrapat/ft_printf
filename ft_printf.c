/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+     +#+           */
/*   Created: 2022/03/26 20:13:59 by ppetchda          #+#    #+#             */
/*   Updated: 2022/03/26 20:18:35 by ppetchda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_print_format(va_list args, t_type my_type)
{
	int		length;

	length = 0;
	if (my_type.flag == 'c')
		length += ft_printf_print_char(va_arg(args, unsigned int));
	else if (my_type.flag == 's')
		length += ft_printf_print_string(va_arg(args, char *));
	else if (my_type.flag == 'd' || my_type.flag == 'i')
		length += ft_printf_print_decimal(va_arg(args, int));
	else if (my_type.flag == 'x' || my_type.flag == 'X')
		length += ft_printf_print_hexadecimal(va_arg(args, unsigned int), my_type.flag);
	else if (my_type.flag == 'u')
		length += ft_printf_print_unsigned(va_arg(args, unsigned int));
	else if (my_type.flag == 'p')
		length += ft_printf_print_pointer(va_arg(args, unsigned long));
	else if (my_type.flag == '%')
		length += ft_printf_print_percent();
	return (length);
}

static int	ft_printf_parse_format(va_list args, t_type my_type)
{
	int		length;

	length = 0;
	length = ft_printf_print_format(args, my_type);
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int			length;
	va_list		args;
	t_type		my_type;

	va_start(args, str);
	length = 0;
	while (*str)
	{
		if (*str == '%')
		{
			my_type.flag = *(str + 1);
			length += ft_printf_parse_format(args, my_type);
			str++;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			length++;
		}
		str++;
	}
	va_end(args);
	return (length);
}
