/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_puthexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:52:56 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/03/03 17:52:29 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_pf_puthexa(unsigned long int nb, char type, int i)
{
	char	*base;
	char	c;
	int		n;

	if (type == 'x')
		base = "0123456789abcdef";
	else if (type == 'X')
		base = "0123456789ABCDEF";
	if (nb < 16)
	{
		c = base[nb];
		write (1, &c, 1);
		i++;
	}
	else if (nb >= 16)
	{
		i++;
		i = ft_pf_puthexa((nb / 16), type, i);
		n = nb % 16;
		c = base[n];
		write (1, &c, 1);
	}
	return (i);
}
