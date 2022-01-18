/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:37:29 by abazizi           #+#    #+#             */
/*   Updated: 2021/11/05 16:06:53 by abazizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static int	ft_isspace(int c)
{
	char	sp;

	sp = ' ';
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || \
			c == '\r' || c == sp);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long		n;
	long long		sign;

	i = 0;
	n = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		n *= 10;
		n += str[i] - '0';
		i++;
	}
	return ((int)sign * (int)n);
}
