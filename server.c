/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:17:46 by fgras-ca          #+#    #+#             */
/*   Updated: 2023/07/24 18:55:48 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_ack(int pid)
{
	kill(pid, SIGUSR1);
}

void	receive_bit(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			ft_putchar_fd('\n', 1);
			send_ack(client_pid);
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
	}
	else
		c <<= 1;
	send_ack(client_pid);
}

void	setup_signals(void)
{
	struct sigaction	s_sigaction;

	ft_memset(&s_sigaction, 0, sizeof(struct sigaction));
	s_sigaction.sa_sigaction = receive_bit;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigemptyset(&s_sigaction.sa_mask);
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
}

int	main(void)
{
	ft_printf("Server PID: ");
	ft_printf("%d", getpid());
	ft_printf("\n");
	setup_signals();
	while (1)
		pause();
	return (0);
}
