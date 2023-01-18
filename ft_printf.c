/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricosta- <ricosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:50:52 by ricosta-          #+#    #+#             */
/*   Updated: 2023/01/17 17:41:00 by ricosta-         ###   ########.fr       */
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
		return \
		(ft_putnbr_hex((unsigned long)va_arg(args, unsigned int), 16, 'x'));
	else if (str[i + 1] == 'X')
		return \
		(ft_putnbr_hex((unsigned long)va_arg(args, unsigned int), 16, 'X'));
	else if (str[i + 1] == 'p')
		return (ft_putptr(va_arg(args, unsigned long)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if ((str[i] == '%') && (ft_strchr("cspdiuxX%", str[i + 1])))
		{
			len += ft_print_arg(str, i, args);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

/*int main (void)
{
	int	a, b;

	a = ft_printf("%d\n", -1);
	b = printf("%d\n", -1);
	printf("a : %d \n b : %d\n", a, b);
	a = ft_printf("%d\n", 1898);
	b = printf("%d\n", 1898);
	printf("a : %d \n b : %d\n", a, b);
}*/