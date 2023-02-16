/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:09:44 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/03/30 17:36:26 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_selection(const char tp, va_list args, int i)
{
	if (tp == 'c')
		i += ft_pf_putchar(va_arg(args, int));
	if (tp == 's')
		i += ft_pf_putstr(va_arg(args, char *));
	if (tp == 'p')
	{
		write (1, "0x", 2);
		i += 2;
		i += ft_pf_putptr(va_arg(args, unsigned long int), 0);
	}
	if (tp == 'd' || tp == 'i')
		i += ft_pf_putdec((va_arg(args, int)), 0);
	if (tp == 'u')
		i += ft_pf_putdec((va_arg(args, unsigned int)), 0);
	if (tp == 'x' || tp == 'X')
		i += ft_pf_puthexa(va_arg(args, unsigned int), tp, 0);
	if (tp == '%')
	{
		write (1, "%", 1);
		i++;
	}
	if (tp != 'c' && tp != 's' && tp != 'p' && tp != 'd' && \
		tp != 'i' && tp != 'u' && tp != 'x' && tp != 'X' && tp != '%')
		i += 0;
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		res;
	va_list	args;

	i = 0;
	res = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			res += ft_selection(str[i + 1], args, 0);
			res--;
			i++;
		}
		else
			write (1, &str[i], 1);
		res++;
		i++;
	}
	va_end(args);
	return (res);
}
