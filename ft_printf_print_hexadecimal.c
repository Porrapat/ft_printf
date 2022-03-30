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

static void print_hex_digit(int number, char flag)
{
	if(number < 10) 
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
}

int ft_printf_hex_recursive(int number, char flag)
{
	int length;
	int remainder;

	length = 0;
	if (number > 0)
	{
		remainder = 0;
		remainder = number % 16;
		print_hex_digit(remainder, flag);
		length += 1;
		length += ft_printf_hex_recursive(number / 16, flag);
	}
	return (length);
}

int	ft_printf_print_hexadecimal(int number, char flag)
{
	int length;

	length = 0;
	length = ft_printf_hex_recursive(number, flag);
	return (length);
}

	// number = 255;

	// 255 % 16 = 15
	// 255 / 16

	// while (number > 0)
	// {
		
	// 	number /= 16;
	// }
	// num = 15;
	// number = 15;
	// if (flag = 'x')
	// {
	// 	ft_putchar_fd('0' + number , 1);
	// }
	// else if (flag = 'X')
	// {

	// }

	// int	i;

	// i = 0;
	// while(i < 16)
	// {
	// 	print_hex_digit(i, flag);
	// 	ft_putchar_fd('\n', 1);
	// 	i++;
	// }
