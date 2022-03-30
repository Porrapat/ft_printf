/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_hexadecimal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+     +#+           */
/*   Created: 2022/03/26 20:13:59 by ppetchda          #+#    #+#             */
/*   Updated: 2022/03/26 20:18:35 by ppetchda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_digit(unsigned int number, char flag)
{
	if (number < 10)
	{
		ft_putchar_fd('0' + number, 1);
	}
	else
	{
		if (flag == 'x')
			ft_putchar_fd('a' - 10 + number, 1);
		else
			ft_putchar_fd('A' - 10 + number, 1);
	}
	return (1);
}

static int	ft_printf_hex_recursive(unsigned int number, char flag)
{
	int	length;
	int	remainder;

	length = 0;
	if (number > 0)
	{
		remainder = 0;
		remainder = number % 16;
		length += ft_printf_hex_recursive(number / 16, flag);
		length += print_hex_digit(remainder, flag);
	}
	return (length);
}

int	ft_printf_print_hexadecimal(unsigned int number, char flag)
{
	int	length;

	length = 0;
	if (number == 0)
		length += print_hex_digit(0, flag);
	else
		length = ft_printf_hex_recursive(number, flag);
	return (length);
}
