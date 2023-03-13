/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:36:57 by abuonomo          #+#    #+#             */
/*   Updated: 2023/02/06 18:02:23 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
%c Prints a single character.
%s Prints a string (as defined by the common C convention).
%p The void * pointer argument has to be printed in hexadecimal format.
%d Prints a decimal (base 10) number.
%i Prints an integer in base 10.
%u Prints an unsigned decimal (base 10) number.
%x Prints a number in hexadecimal (base 16) lowercase format.
%X Prints a number in hexadecimal (base 16) uppercase format.
%% Prints a percent sign.
*/
#include "ft_printf.h"

int	ft_printf_type(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (c == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		count += ft_print_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		count += ft_print_nbr(va_arg(args, long long));
	else if (c == 'u')
		count += ft_print_uns(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		count += ft_print_per();
	return (count);
}
