/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrhex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:31:16 by fgras-ca          #+#    #+#             */
/*   Updated: 2023/03/21 14:45:30 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_ptrhex_pf(unsigned long c, int pref)
{
	int	count;

	count = 0;
	if (!c)
		return (write(1, "(nil)", 5));
	if (pref == 1)
	{
		count += write(1, "0x", 2);
		pref = 0;
	}
	if (c >= 16)
		count += ft_ptrhex_pf(c / 16, pref);
	write(1, &"0123456789abcdef"[c % 16], 1);
	return (count + 1);
}
