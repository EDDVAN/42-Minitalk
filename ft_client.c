/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:29:00 by abazizi           #+#    #+#             */
/*   Updated: 2022/01/17 09:29:03 by abazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_sendchar(int pid, int c)
{
    int bit;

    bit = 8;
    while (bit--)
        {
        if(c % 2 == 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(200);
        c = c / 2;
    }
}

int main(int ac, char **av)
{
    int i;
    int pid;

    i = 0;
    pid = ft_atoi(av[1]);
    if(ac == 3)
    {
        while (av[2][i])
        {
            ft_sendchar(pid, av[2][i]);
            i++;
        }
        ft_sendchar(pid, '\n');
    }
}