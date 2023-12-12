/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:30:31 by fgras-ca          #+#    #+#             */
/*   Updated: 2023/07/21 22:35:00 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

int	g_acknowledged;

void	sigusr1_handler(int sig);
void	send_ack(int pid);
void	receive_bit(int sig, siginfo_t *info, void *context);

#endif
