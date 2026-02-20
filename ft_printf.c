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

int	ft_handle(va_list args, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_adress(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_putunsignednbr(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_hexadecimal(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		len += ft_hexadecimal(va_arg(args, unsigned int), 1);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = -1;
	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (!format[++i])
			{
				len = -1;
				break ;
			}
			len += ft_handle(args, format[i]);
		}
		else
			len += ft_putchar(format[i]);
	}
	va_end(args);
	return (len);
}
