/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orclaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:42:02 by orclaudi          #+#    #+#             */
/*   Updated: 2026/09/21 17:58:04 by gumota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_size(t_stack *st)
{
	int		size;
	t_node	*node;

	if (!st)
		return (0);
	size = 0;
	node = st->top;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

static int	get_max_pos(t_stack *st)
{
	int		max_idx;
	int		max_pos;
	int		current_pos;
	t_node	*node;

	if (!st || !st->top)
		return (-1);
	node = st->top;
	max_idx = node->index;
	max_pos = 0;
	current_pos = 0;
	while (node)
	{
		if (node->index > max_idx)
		{
			max_idx = node->index;
			max_pos = current_pos;
		}
		node = node->next;
		current_pos++;
	}
	return (max_pos);
}

static void	push_chunks_to_b(t_stack *a, t_stack *b, int size, t_flags *flags)
{
	int	i;

	i = 0;
	while (a->top)
	{
		if (a->top->index <= i)
		{
			pb(a, b, flags);
			if (a->top && a->top->index > i + size)
				rr(a, b, flags);
			else
				rb(b, flags);
			i++;
		}
		else if (a->top->index <= i + size)
		{
			pb(a, b, flags);
			i++;
		}
		else
			ra(a, flags);
	}
}

static void	push_back_to_a(t_stack *a, t_stack *b, t_flags *flags)
{
	int	max_pos;
	int	size;

	while (b->top)
	{
		size = stack_size(b);
		max_pos = get_max_pos(b);
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(b, flags);
		}
		else
		{
			while (max_pos++ < size)
				rrb(b, flags);
		}
		pa(a, b, flags);
	}
}

void	sort_medium(t_stack *a, t_stack *b, t_flags *flags)
{
	int	size;
	int	chunk_size;

	if (!a || !a->top)
		return ;
	size = stack_size(a);
	if (size <= 100)
		chunk_size = 15;
	else
		chunk_size = 35;
	push_chunks_to_b(a, b, chunk_size, flags);
	push_back_to_a(a, b, flags);
}
