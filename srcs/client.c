/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:48:49 by yel-alja          #+#    #+#             */
/*   Updated: 2025/02/14 18:30:15 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int		g_int;

void	signals_sender(char c, pid_t pid)
{
	int	bit;
	int	byte;

	byte = 0;
	while (byte < 8)
	{
		bit = (c >> byte) & 1;
		if (bit == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		while (g_int == 0)
			usleep(50);
		g_int = 0;
		byte++;
	}
}

void	handler(int sig)
{
	(void)sig;
	g_int = 1;
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	if (ac != 3)
	{
		write(1, "the arguments must be like this :", 33);
		write(1, "./client <server_pid> <string_to_send>\n", 39);
		exit(1);
	}
	pid = ft_atoi(av[1]);
	i = 0;
	signal(SIGUSR1, handler);
	while (av[2][i])
	{
		signals_sender(av[2][i], pid);
		i++;
	}
	return (0);
}
