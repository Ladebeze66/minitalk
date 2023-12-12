/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:37:50 by fgras-ca          #+#    #+#             */
/*   Updated: 2023/07/27 13:54:38 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sigusr1_handler(int sig)
{
	(void)sig;
	g_acknowledged = 1;
}

void	message_received_handler(int sig)
{
	(void)sig;
	ft_putstr_fd("server >> message received.\n", 1);
}

static void	send_char(int pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		g_acknowledged = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		while (!g_acknowledged)
			pause();
	}
}

static void	mt_kill(int pid, char *str)
{
	signal(SIGUSR1, sigusr1_handler);
	signal(SIGUSR2, message_received_handler);
	while (*str)
		send_char(pid, *str++);
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	mt_kill(ft_atoi(argv[1]), argv[2]);
	return (0);
}
