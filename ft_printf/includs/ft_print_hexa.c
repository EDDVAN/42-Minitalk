/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:27:43 by abazizi           #+#    #+#             */
/*   Updated: 2021/11/17 17:31:45 by abazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_inc.h"

int	ft_print_hexa(unsigned long hexa, int postback, char c)
{
	char		*base;
	static int	x = 0;

	if (postback == 1)
		x = 0;
	if (c == 'm')
		base = "0123456789abcdef";
	else if (c == 'M')
		base = "0123456789ABCDEF";
	if (hexa <= 15)
		x += ft_putchar_fd(base[hexa], 1);
	if (hexa > 15)
	{
		ft_print_hexa(hexa / 16, 0, c);
		ft_print_hexa(hexa % 16, 0, c);
	}
	return (x);
}
