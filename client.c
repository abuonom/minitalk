/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:10:56 by abuonomo          #+#    #+#             */
/*   Updated: 2023/03/13 19:05:26 by abuonomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "./ft_printf/ft_printf.h"

void	confirm(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("MESSAGE RECEIVED\n");
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\f' || str[i] == ' '
		||str[i] == '\r' || str[i] == '\v')
	i++;
	if (str[i] == '-')
	sign = -1;
	if (str[i] == '-' || str[i] == '+')
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

void	ft_bthandler(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = -1;
	if (argc != 3)
	{
		ft_printf("Number of parameters invalid");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][++i] != '\0')
		ft_bthandler(argv[2][i], pid);
	signal(SIGUSR2, confirm);
	ft_bthandler('\0', pid);
	return (0);
}
