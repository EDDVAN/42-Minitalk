/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:24:20 by abazizi           #+#    #+#             */
/*   Updated: 2021/11/17 17:24:30 by abazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_inc.h"

int	ft_putnbr_fd_u(unsigned int n, int fd, int postback)
{
	static int	x = 0;

	if (postback == 1)
	{
		x = 0;
		postback = 0;
	}
	if ((n >= 0) && (n <= 9))
	{
		x += ft_putchar_fd(n + '0', 1);
	}
	if (n > 9)
	{
		ft_putnbr_fd_u((n / 10), fd, 0);
		ft_putnbr_fd_u((n % 10), fd, 0);
	}
	return (x);
}
