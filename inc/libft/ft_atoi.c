/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:23:03 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/06/27 16:52:45 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long int	res;
	int					neg;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == 32 || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == 45)
		neg = -1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		res = res * 10 + str[i] - '0';
		if ((res >= 2147483649 && neg == -1) || (res >= 2147483648 && neg == 1))
			return (-1);
		i++;
	}
	res = res * neg;
	return ((int)res);
}
