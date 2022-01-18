/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:41:09 by abazizi           #+#    #+#             */
/*   Updated: 2021/11/19 19:40:51 by abazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_split_function(char c, va_list args, int f)
{
	long int				pv;

	if (c == 'X')
		f += ft_print_hexa(va_arg(args, unsigned int), 1, 'M');
	else if (c == 'x')
		f += ft_print_hexa(va_arg(args, unsigned int), 1, 'm');
	else if (c == 'p')
	{
		pv = va_arg(args, unsigned long int);
		f += ft_putstr_fd("0x", 1);
		f += ft_print_hexa(pv, 1, 'm');
	}
	return (f);
}

int	ft_print_conversion(char c, va_list args, int f)
{
	if (c == 'd' || c == 'i')
		f += ft_putnbr_fd(va_arg(args, int), 1, 1);
	else if (c == 'u')
		f += ft_putnbr_fd_u(va_arg(args, unsigned int), 1, 1);
	else if (c == 'c')
		f += ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		f += ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == '%')
		f += ft_putchar_fd('%', 1);
	else if (c == 'p' || c == 'x' || c == 'X')
		f = ft_split_function(c, args, f);
	else
		f += ft_putchar_fd(c, 1);
	return (f);
}

int	ft_printf(const char *str, ...)
{
	va_list					args;
	int						i;
	int						f;

	i = 0;
	f = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			f += ft_putchar_fd(str[i], 1);
		else
		{
			f = ft_print_conversion(str[i + 1], args, f);
			i++;
		}
		i++;
	}
	va_end(args);
	return (f);
}
