/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 13:40:30 by gumota            #+#    #+#             */
/*   Updated: 2026/09/22 14:42:01 by gumota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pivot(t_stack *st, int len)
{
	int		min;
	int		max;
	t_node	*node;

	node = st->top;
	min = node->index;
	max = node->index;
	while (len-- > 0)
	{
		if (node->index < min)
			min = node->index;
		if (node->index > max)
			max = node->index;
		node = node->next;
	}
	return ((min + max) / 2);
}
