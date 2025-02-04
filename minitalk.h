/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:37:09 by yel-alja          #+#    #+#             */
/*   Updated: 2025/02/03 10:13:16 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_atoi(char *str);
void				ft_putnbr(int nbr);

typedef struct s_global
{
	unsigned char	re;
	int				i;
	pid_t			old_pid;
}					t_global;

#endif
