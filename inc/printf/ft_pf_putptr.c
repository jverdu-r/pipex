/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:16:17 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/03/02 16:09:31 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_pf_putptr(unsigned long int ptr, int i)
{
	int		n;
	int		res;
	char	*base;
	char	c;

	res = i;
	base = "0123456789abcdef";
	if (ptr < 16)
	{
		c = base[ptr];
		res++;
		write (1, &c, 1);
		return (res);
	}
	else if (ptr >= 16)
	{
		res++;
		res = ft_pf_putptr(ptr / 16, res);
		n = ptr % 16;
		c = base[n];
		write (1, &c, 1);
	}
	return (res);
}
