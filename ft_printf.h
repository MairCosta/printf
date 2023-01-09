/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricosta- <ricosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:30:38 by ricosta-          #+#    #+#             */
/*   Updated: 2023/01/09 17:01:48 by ricosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# define HEXUP "0123456789ABCDEF"
# define HEXLOW "0123456789abcdef"

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

# include "../libft/libft.h"

int			ft_printf(const char *, ...);
static int	ft_putchar_fd(char c);
static int	ft_putstr(char *str);
static int	ft_putchar(char c);


#endif