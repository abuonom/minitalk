/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:12:56 by abuonomo          #+#    #+#             */
/*   Updated: 2023/02/06 13:16:29 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_ptr(unsigned long long p)
{
	if (p >= 16)
	{
		ft_put_ptr(p / 16);
		ft_put_ptr(p % 16);
	}
	else
	{
		if (p > 9)
			ft_putchar(p - 10 + 'a');
		else
			ft_putchar(p + 48);
	}
}

int	ft_ptrlen(unsigned long long p)
{
	int	count;

	count = 0;
	while (p != 0)
	{
		p /= 16;
		count++;
	}
	return (count);
}

int	ft_print_ptr(unsigned long long p)
{
	int	count;

	count = 0;
	if (p == 0)
	{
		count += ft_print_str("0x0");
		return (count);
	}
	count += ft_print_str("0x");
	count += ft_ptrlen(p);
	ft_put_ptr(p);
	return (count);
}
