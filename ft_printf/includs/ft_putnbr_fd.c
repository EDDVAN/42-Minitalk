/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:24:20 by abazizi           #+#    #+#             */
/*   Updated: 2021/11/17 17:24:30 by abazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_inc.h"

int	ft_putnbr_fd(int n, int fd, int postback)
{
	long		i;
	static int	x = 0;

	i = n;
	if (postback == 1)
	{
		x = 0;
		postback = 0;
	}
	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		i = i * -1;
		x++;
	}
	if ((i >= 0) && (i <= 9))
	{
		x += ft_putchar_fd((i + '0'), fd);
	}
	if (i > 9)
	{
		ft_putnbr_fd((i / 10), fd, 0);
		ft_putnbr_fd((i % 10), fd, 0);
	}
	return (x);
}
