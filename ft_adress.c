/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysdurma <aysdurma@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:52:37 by aysdurma          #+#    #+#             */
/*   Updated: 2026/02/19 00:52:37 by aysdurma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_hex(unsigned long n)
{
	int		len;
	char	*base;
	int		tmp;

	len = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		tmp = ft_putptr_hex(n / 16);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (ft_putchar(base[n % 16]) == -1)
		return (-1);
	return (len + 1);
}

int	ft_adress(unsigned long ptr)
{
	int	len;
	int	tmp;

	len = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	tmp = ft_putstr("0x");
	if (tmp == -1)
		return (-1);
	len += tmp;
	tmp = ft_putptr_hex(ptr);
	if (tmp == -1)
		return (-1);
	len += tmp;
	return (len);
}
