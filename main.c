/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+     +#+           */
/*   Created: 2022/03/26 20:13:59 by ppetchda          #+#    #+#             */
/*   Updated: 2022/03/26 20:18:35 by ppetchda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int len;
	ft_printf("%x\n", 9);
	ft_printf("Hello\n");
	ft_printf("%x\n", 15);
	ft_printf("Hello\n");
	ft_printf("%x\n", 16);
	ft_printf("Hello\n");
	len = ft_printf("%x\n", -1);
	printf("%d\n", len);
	len = printf("%x\n", -1);
	printf("%d\n", len);
	return (0);
}
