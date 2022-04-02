/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+     +#+           */
/*   Created: 2022/03/26 20:13:59 by ppetchda          #+#    #+#             */
/*   Updated: 2022/03/26 20:18:35 by ppetchda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_addlead(char *str, int num, t_type my_type)
{
	if (my_type.mode_0 || my_type.mode_dot)
		return (str);
	if (my_type.mode_lead == '#')
	{
		if (!num || my_type.mode_0)
			return (str);
		*--str = my_type.flag;
		*--str = '0';
		return (str);
	}
	if (num < 0)
	{
		*--str = '-';
		return (str);
	}
	if (!my_type.mode_lead)
		return (str);
	*--str = my_type.mode_lead;
	return (str);
}

static int	ft_printlead(int num, t_type my_type)
{
	if (!my_type.mode_0 && !my_type.mode_dot)
		return (0);
	if (my_type.mode_lead == '#')
	{
		if (!num)
			return (0);
		write(1, "0", 1);
		write(1, &my_type.flag, 1);
		return (2);
	}
	if (num < 0)
	{
		write(1, "-", 1);
		return (1);
	}
	if (!my_type.mode_lead)
		return (0);
	write(1, &my_type.mode_lead, 1);
	return (1);
}

int	ft_printformat(char *str, int slen, int num, t_type my_type)
{
	int	printlen;

	if (my_type.mode_0 || my_type.mode_dot)
	{
		printlen = ft_printlead(num, my_type);
		if (my_type.mode_dot)
			my_type.width += printlen;
		ft_writenchar('0', my_type.width - printlen - slen);
		write(1, str, slen);
		return (ft_max(slen + printlen, my_type.width));
	}
	if (my_type.width <= slen)
		return (write(1, str, slen));
	if (my_type.mode_left)
	{
		write(1, str, slen);
		ft_writenchar(' ', my_type.width - slen);
	}
	else
	{
		ft_writenchar(' ', my_type.width - slen);
		write(1, str, slen);
	}
	return (my_type.width);
}
