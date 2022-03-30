/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_unsigned.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+     +#+           */
/*   Created: 2022/03/26 20:13:59 by ppetchda          #+#    #+#             */
/*   Updated: 2022/03/26 20:18:35 by ppetchda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_unsigned_long_hex_digit(unsigned long number)
{
	if (number < 10)
		ft_putchar_fd('0' + number, 1);
	else
		ft_putchar_fd('a' - 10 + number, 1);
	return (1);
}

static int	ft_printf_unsigned_long_hex_recursive(unsigned long number)
{
	int	length;
	int	remainder;

	length = 0;
	if (number > 0)
	{
		remainder = 0;
		remainder = number % 16;
		length += ft_printf_unsigned_long_hex_recursive(number / 16);
		length += print_unsigned_long_hex_digit(remainder);
	}
	return (length);
}

int	ft_printf_print_pointer(unsigned long number)
{
	int	length;

	length = 0;
	ft_putstr_fd("0x", 1);
	if (number == 0)
		length += print_unsigned_long_hex_digit(0);
	else
		length = ft_printf_unsigned_long_hex_recursive(number);

	length += 2;
	return (length);
}

/*
int	ft_printf_print_pointer(unsigned long number)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
	return (0);
}
*/