/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricosta- <ricosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:09:44 by mair              #+#    #+#             */
/*   Updated: 2023/01/17 17:43:25 by ricosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && (char)c != str[i])
		i++;
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (0);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n < 0 && n != INT_MIN)
	{
		len += ft_putchar('-');
		n = -n;
	}
	if (n == INT_MIN)
		len += ft_putstr("-2147483648");
	else if (n <= 9)
		len += ft_putchar(n + '0');
	else
	{
			len += ft_putnbr(n / 10);
			len += ft_putchar((n % 10) + 48);
	}
	return (len);
}

int	ft_putnbr_u(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
	{
		len += ft_putnbr_u(n / 10);
		len += ft_putnbr_u(n % 10);
	}
	else
		len += ft_putchar(n + '0');
	return (len);
}
