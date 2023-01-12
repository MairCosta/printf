/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mair <mair@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:09:44 by mair              #+#    #+#             */
/*   Updated: 2023/01/12 22:25:07 by mair             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr(char *str)
{
    int i;
    
    i = 0;
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

int ft_strlen(const char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

