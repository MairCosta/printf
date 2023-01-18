/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricosta- <ricosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:30:38 by ricosta-          #+#    #+#             */
/*   Updated: 2023/01/17 17:29:47 by ricosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEXUP "0123456789ABCDEF"
# define HEXLOW "0123456789abcdef"

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_print_arg(const char *str, int i, va_list args);
int		ft_putchar(char c);
int		ft_putstr(char *str);
char	*ft_strchr(const char *str, int c);
int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int n);
int		ft_putnbr_hex(unsigned long n, unsigned long base, char c);
int		ft_putptr(unsigned long ptr);

#endif
