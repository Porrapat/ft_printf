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
	ft_printf("%cx%cy%cz\n", 'a', 'b', 'c');
	// ft_printf("ababa\n", 4, 44, 444);
	// ft_printf(1, 4);
	// ft_printf(3, 4, 44, 444);
	// ft_printf(4, 4, 44, 444, 4444);
	// ft_printf("Hello %c%s%%World 555+\n");
	return (0);
}
