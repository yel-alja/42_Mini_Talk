/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:12:18 by yel-alja          #+#    #+#             */
/*   Updated: 2025/02/04 20:48:00 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signals_sender(char str, pid_t pid)
{
	int		bit;
	int		byte;
	int		flag;

	byte = 0;
		while (byte < 8)
		{
			bit = (str >> byte) & 1;
			if (bit == 1)
				flag = kill(pid, SIGUSR1);
			else
				flag = kill(pid, SIGUSR2);
			usleep(600);
			byte++;
		}
	if (flag == -1)
		write(1, "pid is wrong\n", 13);
}
void handler(int sig)
{
	(void)sig;
	// write(1, "received successfully\n", 22);
	exit(0);
}
int	main(int ac, char **av)
{
	pid_t	pid;
	if (ac != 3)
	{
		write (1, "the arguments must be like this :", 33);
		write (1, "./client <server_pid> <string_to_send>\n", 39);
		exit(1);
	}
	pid = ft_atoi(av[1]);
	int i = 0;
	while(av[2][i])
	{
	signals_sender(av[2][i], pid);
	i++;
	}
	signal(SIGUSR1 , handler);
	signals_sender('\0', pid);
	pause();
	return 0;
}
