/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 13:46:09 by gumota            #+#    #+#             */
/*   Updated: 2026/09/23 07:50:00 by gumota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_a(t_stack *a, int len, t_flags *flags)
{
	if (len <= 1)
		return ;
	if (len == 2)
	{
		if (a->top->index > a->top->next->index)
			sa(a, flags);
		return ;
	}
	if (a->top->index > a->top->next->index)
		sa(a, flags);
	if (a->top->next->index > a->top->next->next->index)
	{
		if (a->size == 3)
			rra(a, flags);
		else
		{
			ra(a, flags);
			sa(a, flags);
			rra(a, flags);
		}
	}
	if (a->top->index > a->top->next->index)
		sa(a, flags);
}

void	sort_small_b(t_stack *a, t_stack *b, int len, t_flags *flags)
{
	if (len <= 1)
	{
		if (len == 1)
			pa(a, b, flags);
		return ;
	}
	if (len == 2)
	{
		if (b->top->index < b->top->next->index)
			sb(b, flags);
		pa(a, b, flags);
		pa(a, b, flags);
		return ;
	}
	if (b->top->index < b->top->next->index)
		sb(b, flags);
	if (b->top->next->index < b->top->next->next->index)
	{
		if (b->size == 3)
			rrb(b, flags);
		else
		{
			rb(b, flags);
			sb(b, flags);
			rrb(b, flags);
		}
	}
	if (b->top->index < b->top->next->index)
		sb(b, flags);
	pa(a, b, flags);
	pa(a, b, flags);
	pa(a, b, flags);
}
