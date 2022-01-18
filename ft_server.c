/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:29:11 by abazizi           #+#    #+#             */
/*   Updated: 2022/01/17 09:29:13 by abazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_printchar(int bit)
{
    static  int power = 1;
    static  int byte = 0;

    bit -= SIGUSR1;
    if (power == 128)
    {
        write(1, &byte, 1);
        byte = 0;
        power = 1;
    }
    else
    {
        byte += (power * bit);
        power *= 2;
    }
}

int main(void)
{
    int     pid;
    void	(*f)(int);

	pid = getpid();
	f = &ft_printchar;
	ft_printf("%d\n", pid);
	while (1)
	{
		signal(SIGUSR1, f);
		signal(SIGUSR2, f);
	}
}
