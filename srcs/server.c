/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:36:11 by yel-alja          #+#    #+#             */
/*   Updated: 2025/02/14 18:30:24 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

struct s_global	g_st;

void	sig_handler(int signal, siginfo_t *s_i, void *last)
{
	(void)last;
	if (s_i->si_pid != g_st.old_pid)
	{
		g_st.i = 0;
		g_st.re = 0;
		g_st.old_pid = s_i->si_pid;
	}
	if (signal == SIGUSR1)
	{
		g_st.re = g_st.re | 1 << g_st.i;
		g_st.i++;
	}
	else
		g_st.i++;
	if (g_st.i == 8)
	{
		write(1, &g_st.re, 1);
		g_st.i = 0;
		g_st.re = 0;
	}
	kill(s_i->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa = (struct sigaction){0};
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	write(1, "server pid :", 12);
	ft_putnbr((int)getpid());
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
