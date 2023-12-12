/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:28:13 by fgras-ca          #+#    #+#             */
/*   Updated: 2023/03/21 17:13:33 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_type(va_list *args, char c)
{
	if (c == 'c')
		return (ft_putchar_pf(va_arg((*args), int)));
	else if (c == 's')
		return (ft_putstr_pf(va_arg((*args), char *)));
	else if (c == 'p')
		return (ft_ptrhex_pf(va_arg((*args), unsigned long), 1));
	else if (c == 'd')
		return (ft_decimal_pf(va_arg((*args), int)));
	else if (c == 'i')
		return (ft_decimal_pf(va_arg((*args), int)));
	else if (c == 'u')
		return (ft_unsigned_pf(va_arg((*args), unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_hexnum_pf(va_arg((*args), unsigned int), c));
	else if (c == '%')
		return (write(1, "%", 1));
	else
		return (0);
}
