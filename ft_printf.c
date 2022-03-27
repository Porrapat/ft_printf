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

int	ft_printf(int count, ...)
{
	va_list	args;
	va_start(args, count);
	for	(int i = 0; i < count; ++i) {
		ft_putnbr_fd(va_arg(args, int), 1);
		ft_putstr_fd("\n", 1);
	}
	va_end(args);
	return (0);
}