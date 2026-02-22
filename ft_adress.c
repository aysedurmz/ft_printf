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
	tmp = ft_hexadecimal(ptr, 0);
	if (tmp == -1)
		return (-1);
	len += tmp;
	return (len);
}
