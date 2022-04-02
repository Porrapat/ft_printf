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

char	ft_to_hex_digit(int val, bool isUpper)
{
	if (val <= 9)
		return (val + '0');
	if (isUpper)
		return (val - 10 + 'A' );
	return (val - 10 + 'a' );
}

char	*ft_to_str_hex_buff(char *pendbuff, unsigned long num, bool isUpper)
{
	*pendbuff = '\0';
	if (!num)
	{
		*--pendbuff = '0';
		return (pendbuff);
	}
	while (num > 0)
	{
		*--pendbuff = ft_to_hex_digit(num % 16, isUpper);
		num /= 16;
	}
	return (pendbuff);
}

int	ft_printf_print_hex(unsigned long number, t_type my_type)
{
	char	buff[32];
	char	*str;
	size_t	len;
	size_t	templen;

	str = ft_to_str_hex_buff(&buff[31], number, my_type.flag < 'a');
	if (str)
	{
		str = ft_addlead(str, number != 0, my_type);
		templen = ft_strlen(str);
		len = ft_printformat(str, templen, number != 0, my_type);
	}
	else
		len = 0;
	return (len);
}
