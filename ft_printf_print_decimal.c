/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_decimal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+     +#+           */
/*   Created: 2022/03/26 20:13:59 by ppetchda          #+#    #+#             */
/*   Updated: 2022/03/26 20:18:35 by ppetchda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	get_minus_and_absnumber(int number, unsigned int *numberabs)
{
	bool	minus;

	minus = false;
	if ((unsigned int)number == 0x80000000)
	{
		minus = true;
		*numberabs = 0x80000000;
	}
	else if (number < 0)
	{
		minus = true;
		*numberabs = -number;
	}
	else
	{
		minus = false;
		*numberabs = number;
	}
	return (minus);
}

char	ft_todigit(int val)
{
	if (val <= 9)
		return (val + '0');
	return (val - 10 + 'a' );
}

char	*ft_unsigned_to_str_buff(char *pendbuff, unsigned long num)
{
	*pendbuff = '\0';
	if (!num)
	{
		*--pendbuff = '0';
		return (pendbuff);
	}
	while (num > 0)
	{
		*--pendbuff = ft_todigit(num % 10);
		num /= 10;
	}
	return (pendbuff);
}

int	ft_printf_print_decimal(int number, t_type my_type)
{
	char			buff[32];
	char			*str;
	size_t			len;
	size_t			templen;
	unsigned int	numberabs;

	get_minus_and_absnumber(number, &numberabs);
	str = ft_unsigned_to_str_buff(&buff[31], numberabs);
	if (str)
	{
		str = ft_addlead(str, number, my_type);
		templen = ft_strlen(str);
		len = ft_printformat(str, templen, number, my_type);
	}
	else
		len = 0;
	return (len);
}
