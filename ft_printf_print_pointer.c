/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_pointer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+     +#+           */
/*   Created: 2022/03/26 20:13:59 by ppetchda          #+#    #+#             */
/*   Updated: 2022/03/26 20:18:35 by ppetchda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	printf_null_pointer(t_type my_type)
{
	size_t	len;

	len = 0;
	if (IS_LINUX)
		len += ft_printf_print_string("(nil)", my_type);
	else
		len += ft_printf_print_string("0x0", my_type);
	return (len);
}

int	ft_printf_print_pointer(unsigned long number, t_type my_type)
{
	size_t	len;

	len = 0;
	if (!number)
		len = printf_null_pointer(my_type);
	else
	{
		my_type.mode_lead = '#';
		my_type.flag = 'x';
		len = ft_printf_print_hex(number, my_type);
	}
	return (len);
}
