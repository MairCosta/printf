/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricosta- <ricosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:09:44 by mair              #+#    #+#             */
/*   Updated: 2023/01/14 20:15:13 by ricosta-         ###   ########.fr       */
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
}

int	ft_putnbr_u(unsigned int n)
{
	int len;

	len = 0;
	if (n > 9)
	{
		len += ft_putnbr_u(n / 10);
		len += ft_putnbr_u(n % 10);
	}
	else
		len += ft_putchar(n + 48);
	return (len);
}

int ft_putnbr_hex(long long n, int base, char c)
{
	int 	len;
	char	*low;
	char	*up;

	len = 0;
	low = hexlow;
	up = hexup;
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if (n >= base)
		len += ft_putnbr_hex((n / base), base, c);
	if (c == 'x')
		len += ft_putchar(hexlow[n % base]);
	else if (c == 'X')
		len += ft_putchar(hexup[n % base]);
	return (len);
	}

int ft_putptr(unsigned long long ptr)
{
	int len;

	len = 0;
	if (ptr == 0)
		len += ft_putstr("(nil)");
	else
	{
		len += ft_putstr("0x");
		len += ft_putnbr_hex(ptr, 16, 'x');
	}
	return (len);
}
