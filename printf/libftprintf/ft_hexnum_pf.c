/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexnum_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:34:00 by fgras-ca          #+#    #+#             */
/*   Updated: 2023/03/18 16:42:41 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_hexnum_pf(unsigned int a, char c)
{
	int	count;

	count = 0;
	if (a >= 16)
		count += ft_hexnum_pf(a / 16, c);
	if (c == 'x')
		write(1, &"0123456789abcdef"[a % 16], 1);
	if (c == 'X')
		write(1, &"0123456789ABCDEF"[a % 16], 1);
	return (count +1);
}
