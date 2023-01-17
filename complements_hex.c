/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complements_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mair <mair@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:45:24 by ricosta-          #+#    #+#             */
/*   Updated: 2023/01/17 12:53:36 by mair             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long n, unsigned long base, char c)
{
	int		len;
	char	*low;
	char	*up;

	len = 0;
	low = HEXLOW;
	up = HEXUP;
	if (n >= base)
		len += ft_putnbr_hex((n / base), base, c);
	if (c == 'x')
		len += ft_putchar(low[n % base]);
	else if (c == 'X')
		len += ft_putchar(up[n % base]);
	return (len);
}

int	ft_putptr(unsigned long ptr)
{
	int	len;

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
