/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:36:14 by fgras-ca          #+#    #+#             */
/*   Updated: 2023/03/21 14:51:46 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	int		print_len;
	va_list	args;

	i = 0;
	print_len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			print_len += ft_print_type(&args, s[i + 1]);
			i++;
		}
		else
			print_len += ft_putchar_pf(s[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}
