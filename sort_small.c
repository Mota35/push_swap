/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 13:46:09 by gumota            #+#    #+#             */
/*   Updated: 2026/09/22 14:13:53 by gumota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_a(t_stack *a, int len, t_flags *flags)
{
	int	min_pos;

	if (len <= 1)
		return ;
	if (len == 2)
	{
		if (a->top->index > a->top->next->index)
			sa(a, flags);
		return ;
	}
	min_pos = 0;
	if (a->top->next->index < a->top->index)
		min_pos = 1;
	if (a->top->next->next->index < a->top->index
		&& a->top->next->next->index < a->top->next->index)
		min_pos = 2;
	if (min_pos == 1)
		ra(a, flags);
	else if (min_pos == 2)
		rra(a, flags);
	if (a->top->next->index < a->top->index)
		sa(a, flags);
}

void	sort_small_b(t_stack *a, t_stack *b, int len, t_flags *flags)
{
	int	max_pos;

	if (len <= 1)
	{
		while (len-- > 0)
			pa(a, b, flags);
		return ;
	}
	if (len == 2)
	{
		if (b->top->index < b->top->next->index)
			sb(b, flags);
		while (len-- > 0)
			pa(a, b, flags);
		return ;
	}
	max_pos = 0;
	if (b->top->next->index > b->top->index
		&& b->top->next->index > b->top->next->next->index)
		max_pos = 1;
	else if (b->top->next->next->index > b->top->index
		&& b->top->next->next->index > b->top->next->index)
		max_pos = 2;
	if (max_pos == 1)
		rb(b, flags);
	else if (max_pos == 2)
		rrb(b, flags);
	if (b->top->index < b->top->next->index)
		sb(b, flags);
	while (len-- > 0)
		pa(a, b, flags);
}
