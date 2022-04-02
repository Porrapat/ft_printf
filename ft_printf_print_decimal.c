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

static unsigned int	get_minus_and_absnumber(int number)
{
	unsigned int numberabs;
	if ((unsigned int)number == 0x80000000)
		numberabs = 0x80000000;
	else if (number < 0)
		numberabs = -number;
	else
		numberabs = number;
	return (numberabs);
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

	numberabs = get_minus_and_absnumber(number);
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
