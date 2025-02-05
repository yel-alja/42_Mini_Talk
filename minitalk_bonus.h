/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:15:58 by yel-alja          #+#    #+#             */
/*   Updated: 2025/02/05 09:16:29 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <signal.h>
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
