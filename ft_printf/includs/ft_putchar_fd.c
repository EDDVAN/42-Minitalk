/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:23:35 by abazizi           #+#    #+#             */
/*   Updated: 2021/11/17 17:23:46 by abazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_inc.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
