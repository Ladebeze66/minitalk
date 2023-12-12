/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:16:04 by fgras-ca          #+#    #+#             */
/*   Updated: 2023/03/18 15:56:31 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_decimal_pf(int c);
int	ft_hexnum_pf(unsigned int a, char c);
int	ft_ptrhex_pf(unsigned long c, int pref);
int	ft_unsigned_pf(unsigned int c);
int	ft_print_type(va_list *args, char c);
int	ft_putchar_pf(char c);
int	ft_putstr_pf(char *s);

#endif
