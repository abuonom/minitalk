/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:47:29 by abuonomo          #+#    #+#             */
/*   Updated: 2023/02/06 18:16:59 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

char	*ft_uitoa(unsigned int n);
int		ft_count(int n);
void	ft_putchar(char c);
int		ft_counter_unsigned(unsigned	int num);
void	ft_putstr(char *str);
int		ft_putnbr(long int nbr);
size_t	ft_strlen(const char *str);
int		ft_printf(const char *str, ...);
int		ft_printf_type(char c, va_list args);
int		ft_print_uns(unsigned int n);
int		ft_print_str(char *str);
int		ft_print_ptr(unsigned long long p);
int		ft_print_per(void);
int		ft_print_nbr(int c);
int		ft_print_hex(unsigned int num, const char c);
int		ft_print_char(char c);

#endif
