/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricosta- <ricosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:50:52 by ricosta-          #+#    #+#             */
/*   Updated: 2023/01/16 18:48:40 by ricosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(const char *str, int i, va_list args)
{
	if (str[i + 1] == '%')
		return (ft_putchar(str[i + 1]));
	else if (str[i + 1] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (str[i + 1] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if ((str[i + 1] == 'd') || (str[i + 1] == 'i'))
		return (ft_putnbr(va_arg(args, int)));
	else if (str[i + 1] == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	else if (str[i + 1] == 'x')
		return (ft_putnbr_hex((long long)va_arg(args, unsigned int), 16, 'x'));
	else if (str[i + 1] == 'X')
		return (ft_putnbr_hex((long long)va_arg(args, unsigned int), 16, 'X'));
	else if (str[i + 1] == 'p')
		return (ft_putptr(va_arg(args, unsigned long long)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, str);
	while (str[i])
	{
		if ((str[i] == '%') && (ft_strchr("cspdiuxX%", str[i + 1])))
		{
			len += ft_print_arg(str, i, args);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
