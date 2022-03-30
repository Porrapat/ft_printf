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

int	ft_printf_print_hexadecimal(int number, char flag)
{
	/*
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
	*/

	// num = 15;
	// number = 15;
	// if (flag = 'x')
	// {
	// 	ft_putchar_fd('0' + number , 1);
	// }
	// else if (flag = 'X')
	// {

	// }

	int	i;

	i = 0;
	while(i < 16)
	{
		print_hex_digit(i, flag);
		ft_putchar_fd('\n', 1);
		i++;
	}

	return (0);
}
