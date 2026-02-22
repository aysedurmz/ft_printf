/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysdurma <aysdurma@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:52:25 by aysdurma          #+#    #+#             */
/*   Updated: 2026/02/19 00:52:25 by aysdurma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_handle(va_list args, char format)
{
	int	tmp;

	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (format == 'p')
		return (ft_adress(va_arg(args, unsigned long)));
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (format == 'u')
		return (ft_putunsignednbr(va_arg(args, unsigned int)));
	if (format == 'x')
		return (ft_hexadecimal(va_arg(args, unsigned int), 0));
	if (format == 'X')
		return (ft_hexadecimal(va_arg(args, unsigned int), 1));
	if (format == '%')
		return (ft_putchar('%'));
	if (ft_putchar('%') == -1)
		return (-1);
	tmp = ft_putchar(format);
	if (tmp == -1)
		return (-1);
	return (tmp + 1);
}

static int	ft_process(va_list args, const char *format, int *i)
{
	int	tmp;

	if (format[*i] == '%')
	{
		(*i)++;
		if (!format[*i])
			return (-1);
		tmp = ft_handle(args, format[*i]);
	}
	else
		tmp = ft_putchar(format[*i]);
	return (tmp);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		tmp;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		tmp = ft_process(args, format, &i);
		if (tmp == -1)
		{
			len = -1;
			break ;
		}
		len += tmp;
		i++;
	}
	va_end(args);
	return (len);
}
