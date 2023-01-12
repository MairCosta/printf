/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mair <mair@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:50:52 by ricosta-          #+#    #+#             */
/*   Updated: 2023/01/12 22:09:24 by mair             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_arg(const char *str, int i, va_list args)
{
	if (str[i + 1] == '%')
		return (ft_putchar(str[i + 1]));
		
	else if (str[i + 1] == 'c')
		return (ft_putchar(va_arg(args, int)));
		
	else if (str[i + 1] == 's')
		return (ft_putstr(va_arg(args, char *))); //tratar caso seja nulo
		
	else if ((str[i +1] == 'd') || (str[i + 1] == 'i'))
		return (ft_putnbr(va_arg(args, int)));
	
	else if (str[i + 1] == 'u')
		return () // idk
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int 	len;
	int		i;
	
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
	}  
	va_end(args);
	return (len);
}
