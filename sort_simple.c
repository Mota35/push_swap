/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orclaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 13:44:11 by orclaudi          #+#    #+#             */
/*   Updated: 2026/09/21 10:28:15 by gumota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_stack *a)
{
	t_node	*node;
	int		min_index;
	int		pos;
	int		min_pos;

	node = a->top;
	min_index = node->index;
	min_pos = 0;
	pos = 0;
	while (node)
	{
		if (node->index < min_index)
		{
			min_index = node->index;
			min_pos = pos;
		}
		node = node->next;
		pos++;
	}
	return (min_pos);
}

static void	move_min_to_top(t_stack *a, int pos, t_flags *flags)
{
	if (pos <= a->size / 2)
	{
		while (pos > 0)
		{
			ra(a, flags);
			pos--;
		}
	}
	else
	{
		while (pos < a->size)
		{
			rra(a, flags);
			pos++;
		}
	}
}

void	sort_simple(t_stack *a, t_stack *b, t_flags *flags)
{
	int	pos;

	while (a->size > 0)
	{
		pos = find_min_pos(a);
		move_min_to_top(a, pos, flags);
		pb(a, b, flags);
	}
	while (b->size > 0)
		pa(a, b, flags);
}
