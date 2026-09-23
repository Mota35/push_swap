/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 02:05:40 by gumota            #+#    #+#             */
/*   Updated: 2026/09/12 16:26:50 by gumota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	teste(const char *nptr, int i, long *nbr, int sinal)
{
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (*nbr > (2147483647 - (nptr[i] - '0')) / 10)
			return (0);
		*nbr = (*nbr * 10) + (nptr[i] - '0');
		i++;
	}
	*nbr *= sinal;
	if ((sinal == 1 && *nbr > 2147483647)
		|| (sinal == -1 && *nbr < -2147483648))
		return (0);
	return (1);
}

long	ft_atoi(const char *nptr, int *temp)
{
	int		i;
	int		sinal;
	long	valor;

	valor = 0;
	i = 0;
	sinal = 1;
	if (!nptr)
		return (0);
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sinal = -1;
		i++;
	}
	if (!teste(nptr, i, &valor, sinal))
		return (0);
	*temp = (int)valor;
	return (1);
}
