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
	printf("-------- my ft_printf --------\n");
	ft_printf("%c", '0');
	ft_printf(" %c", '0' - 256);
	ft_printf("%c ", '0' + 256);
	ft_printf(" %c %c %c ", '0', 0, '1');
	ft_printf(" %c %c %c ", ' ', ' ', ' ');
	ft_printf(" %c %c %c ", '1', '2', '3');
	ft_printf(" %c %c %c ", '2', '1', 0);
	ft_printf(" %c %c %c ", 0, '1', '2');

	printf("-------- d my ft_printf --------\n");
	printf("length is %d\n", ft_printf("%c", '0'));
	printf("length is %d\n", ft_printf(" %c", '0' - 256));
	printf("length is %d\n", ft_printf("%c ", '0' + 256));
	printf("length is %d\n", ft_printf(" %c %c %c ", '0', 0, '1'));
	printf("length is %d\n", ft_printf(" %c %c %c ", ' ', ' ', ' '));
	printf("length is %d\n", ft_printf(" %c %c %c ", '1', '2', '3'));
	printf("length is %d\n", ft_printf(" %c %c %c ", '2', '1', 0));
	printf("length is %d\n", ft_printf(" %c %c %c ", 0, '1', '2'));

	printf("\n\n");

	printf("-------- printf --------\n");
	printf("%c", '0');
	printf(" %c", '0' - 256);
	printf("%c ", '0' + 256);
	printf(" %c %c %c ", '0', 0, '1');
	printf(" %c %c %c ", ' ', ' ', ' ');
	printf(" %c %c %c ", '1', '2', '3');
	printf(" %c %c %c ", '2', '1', 0);
	printf(" %c %c %c ", 0, '1', '2');

	printf("-------- d printf --------\n");
	printf("length is %d\n", printf("%c", '0')); // 1
	printf("length is %d\n", printf(" %c", '0' - 256)); // 2
	printf("length is %d\n", printf(" %c", '0' - 256)); // 2
	printf("length is %d\n", printf(" %c %c %c ", '0', 0, '1')); // 7
	printf("length is %d\n", printf(" %c %c %c ", ' ', ' ', ' ')); // 7
	printf("length is %d\n", printf(" %c %c %c ", '1', '2', '3')); // 7
	printf("length is %d\n", printf(" %c %c %c ", '2', '1', 0)); // 7
	printf("length is %d\n", printf(" %c %c %c ", 0, '1', '2')); // 7

	// ft_printf("%cx%cy%cz\n", 'a', 'b', 'c');
	// ft_printf("ababa\n", 4, 44, 444);
	// ft_printf(1, 4);
	// ft_printf(3, 4, 44, 444);
	// ft_printf(4, 4, 44, 444, 4444);
	// ft_printf("Hello %c%s%%World 555+\n");
	return (0);
}
