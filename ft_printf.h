/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+     +#+           */
/*   Created: 2022/03/26 20:13:59 by ppetchda          #+#    #+#             */
/*   Updated: 2022/03/26 20:18:35 by ppetchda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_type
{
	char	flag;
}	t_type;

# ifdef __linux__
#  define IS_LINUX 1
# else
#  define IS_LINUX 0
# endif

int		ft_printf(const char *str, ...);

int		ft_printf_print_percent(void);
int		ft_printf_print_char(char c);
int		ft_printf_print_string(char *str);
int		ft_printf_print_decimal(int number);
int		ft_printf_print_hex(unsigned int number, char flag);
int		ft_printf_print_unsigned(unsigned int number);
int		ft_printf_print_pointer(unsigned long number);

#endif