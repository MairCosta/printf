/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricosta- <ricosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:50:52 by ricosta-          #+#    #+#             */
/*   Updated: 2023/01/09 17:36:06 by ricosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(const char *str, va_list args, len)
{
	if (str == 'c' || str == 's' || str == 'p')
		ft_putstr(str);
	if (str == 'p')
	{
		write(1, 'oX', 2);
		*str++;
		ft_putstr(&str);
	}
		ft_putnbr()
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int 	len;
	
	va_start(args, str);
	while (*str)
	{
		if (str == '%')
		{
			*str++;
			if (str == '%')
				write(1, '%', 1);
			result += ft_print(str, args, len);
		}
		*str++; //sim?
	}
	va_end(args);
	return (len);
}
