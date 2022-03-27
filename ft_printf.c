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

#include "libft.h"
#include <stdarg.h>

int ft_printf(const char *str, ...)
{
	va_list	args;
	va_start(args, str);
	while(*str)
	{
		if(*str == '%')
		{
			if(*(str + 1) == 'c')
			{
				ft_putchar_fd(va_arg(args, unsigned int), 1);
			}
			str++;
		}
		else
		{
			ft_putchar_fd(*str, 1);
		}
		str++;
	}
	va_end(args);
	return (0);
}
