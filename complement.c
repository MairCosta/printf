/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricosta- <ricosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:37:03 by ricosta-          #+#    #+#             */
/*   Updated: 2023/01/09 17:27:29 by ricosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_putnbr(int n)
{
	int i = 0;
	if (n == INT_MIN)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
	return (i);
}

static int ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str[i], 1)
		i++;
	}
	return (i);
}
