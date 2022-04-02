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
	char	mode_left;
	char	mode_0;
	char	mode_dot;
	char	mode_lead;
	int		width;
	char	flag;
}	t_type;

# ifdef __linux__
#  define IS_LINUX 1
# else
#  define IS_LINUX 0
# endif

int		ft_printf(const char *str, ...);

int		ft_printf_print_percent(void);
int		ft_printf_print_char(char c, t_type my_type);
int		ft_printf_print_string(char *stmakr, t_type my_type);
int		ft_printf_print_decimal(int number, t_type my_type);
int		ft_printf_print_hex(unsigned long number, t_type my_type);
int		ft_printf_print_unsigned(unsigned int number, t_type my_type);
int		ft_printf_print_pointer(unsigned long number, t_type my_type);

int		ft_char_in_set(char c, const char *charset);
char	*ft_atoi_shift(const char *str, int *retval);
void	ft_writenchar(char ch, int ncopy);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
char	*ft_addlead(char *str, int num, t_type my_type);
int		ft_printformat(char *str, int slen, int num, t_type my_type);

char	*ft_unsigned_itoa(unsigned int n);
char	*ft_hex_itoa(unsigned long n, char flag);

#endif