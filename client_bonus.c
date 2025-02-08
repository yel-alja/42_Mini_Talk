/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:16:59 by yel-alja          #+#    #+#             */
/*   Updated: 2025/02/08 11:23:05 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

void	message(int sig)
{
	(void)sig;
	write(1, "Message sent successfully\n", 26);
	exit(0);
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
	signal(SIGUSR2, message);
	while (av[2][i])
	{
		signals_sender(av[2][i], pid);
		i++;
	}
	signals_sender(0, pid);
	return (0);
}
