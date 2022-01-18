/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_inc.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:22:49 by abazizi           #+#    #+#             */
/*   Updated: 2021/11/17 17:23:23 by abazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INC_H
# define FT_PRINTF_INC_H

# include <stdlib.h>
# include <unistd.h>

int		ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd, int postback);
int		ft_putnbr_fd_u(unsigned int n, int fd, int postback);
int		ft_print_hexa(unsigned long hexa, int postback, char c);

#endif
