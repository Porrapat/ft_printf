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

	ft_printf("%x", 123);
	ft_printf("Hello\n");
	ft_printf("%X", 123);
	// int a;

	// char *s;

	// int len1;
	// int len2;

	// len1 = printf("%p\n", &a);
	// len2 = printf("%p\n", s);

	// printf("%d, %d\n", len1, len2);

	// printf("%x\n", 15);
	// printf("%x\n", 16);
	// printf("%x\n", 17);

	// printf("%X\n", 15);
	// printf("%X\n", 16);
	// printf("%X\n", 17);

	// ft_printf("%s", "Hello", "World", "ABCD");
	// printf("-------- my ft_printf --------\n");

	// ft_printf("%c", '0');
	// ft_printf(" %c ", '0');
	// ft_printf(" %c", '0' - 256);
	// ft_printf("%c ", '0' + 256);
	// ft_printf(" %c %c %c ", '0', 0, '1');
	// ft_printf(" %c %c %c ", ' ', ' ', ' ');
	// ft_printf(" %c %c %c ", '1', '2', '3');
	// ft_printf(" %c %c %c ", '2', '1', 0);
	// ft_printf(" %c %c %c ", 0, '1', '2');

	// char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
	// ft_printf("%s", "");
	// ft_printf(" %s", "");
	// ft_printf("%s ", "");
	// ft_printf(" %s ", "");
	// ft_printf(" %s ", "-");
	// ft_printf(" %s %s ", "", "-");
	// ft_printf(" %s %s ", " - ", "");
	// ft_printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
	// ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	// ft_printf(" NULL %s NULL ", NULL);

	// printf("-------- d my ft_printf --------\n");
	// printf("-------- printf --------\n");
	// printf("-------- d printf --------\n");
	return (0);
}
