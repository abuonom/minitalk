/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:40:22 by abuonomo          #+#    #+#             */
/*   Updated: 2023/02/06 16:44:15 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		count;

	count = ft_counter_unsigned(n);
	num = (char *)malloc(sizeof(char) * (count + 1));
	if (!num)
		return (0);
	num[count] = '\0';
	while (n != 0)
	{
		num[count - 1] = n % 10 + 48;
		n = n / 10;
		count--;
	}
	return (num);
}

int	ft_print_uns(unsigned int n)
{
	int		count;
	char	*num;

	count = 0;
	if (n == 0)
		count += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		count += ft_print_str(num);
		free(num);
	}
	return (count);
}
