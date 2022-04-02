/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+     +#+           */
/*   Created: 2022/03/26 20:13:59 by ppetchda          #+#    #+#             */
/*   Updated: 2022/03/26 20:18:35 by ppetchda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_print_string(char *str, t_type my_type)
{
	int	length;
	int	slen;

	if (str == NULL)
		return (write(1, "(null)", 6));
	slen = ft_strlen(str);
	if (my_type.mode_dot)
		length = ft_min(slen, my_type.width);
	else
		length = ft_max(slen, my_type.width);
	if (length <= slen)
		return (write(1, str, length));
	if (my_type.mode_left)
	{
		write(1, str, slen);
		ft_writenchar(' ', length - slen);
	}
	else
	{
		ft_writenchar(' ', length - slen);
		write(1, str, slen);
	}
	return (length);
}
