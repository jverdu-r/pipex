/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putdec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:36:34 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/02/24 16:51:46 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_pf_putdec(long long int nb, int i)
{
	char		*base;
	char		c;

	base = "0123456789";
	if (nb < 0)
	{
		write (1, "-", 1);
		i++;
		nb = nb * -1;
	}
	if (nb < 10)
	{
		c = base[nb];
		i++;
		write (1, &c, 1);
	}
	else if (nb >= 10)
	{
		i++;
		i = ft_pf_putdec((nb / 10), i);
		nb = nb % 10;
		c = base[nb];
		write (1, &c, 1);
	}
	return (i);
}
