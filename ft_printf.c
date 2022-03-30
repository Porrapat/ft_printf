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

static int	ft_printf_print_format(va_list args, char flag)
{
	int		length;
	char	*str;

	length = 0;
	if (flag == 'c')
		length += ft_printf_print_char(va_arg(args, unsigned int));
	else if (flag == 's')
		length += ft_printf_print_string(va_arg(args, char *));
	else if (flag == 'd' || flag == 'i')
		length += ft_printf_print_decimal(va_arg(args, int));
	else if (flag == 'x' || flag == 'X')
		length += ft_printf_print_hexadecimal(va_arg(args, unsigned int), flag);
	else if (flag == 'u')
		length += ft_printf_print_unsigned(va_arg(args, unsigned int));
	else if (flag == 'p')
		length += ft_printf_print_pointer(va_arg(args, unsigned long));
	else if (flag == '%')
		length += ft_printf_print_percent();
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int			length;
	va_list		args;

	va_start(args, str);
	length = 0;
	while (*str)
	{
		if (*str == '%')
		{
			length += ft_printf_print_format(args, *(str + 1));
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
