/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:12:40 by fgras-ca          #+#    #+#             */
/*   Updated: 2023/03/21 14:47:01 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../ft_printf.h"

int	ft_unsigned_pf(unsigned int c)
{
	int	count;

	count = 0;
	if (c >= 10)
		count += ft_unsigned_pf(c / 10);
	write(1, &"0123456789"[c % 10], 1);
	return (count + 1);
}