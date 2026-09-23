/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:15:08 by gumota            #+#    #+#             */
/*   Updated: 2026/09/22 14:46:45 by gumota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	quicksort_b(t_stack *a, t_stack *b, int len, t_flags *flags);

static void	quicksort_a(t_stack *a, t_stack *b, int len, t_flags *flags)
{
	int	pivot;
	int	pushed;
	int	rotated;
	int	i;

	if (len <= 3)
	{
		sort_small_a(a, len, flags);
		return ;
	}
	pivot = get_pivot(a, len);
	pushed = 0;
	rotated = 0;
	i = 0;
	while (i < len)
	{
		if (a->top->index < pivot)
		{
			pb(a, b, flags);
			pushed++;
		}
		else
		{
			ra(a, flags);
			rotated++;
		}
		i++;
	}
	i = 0;
	while (i < rotated)
	{
		rra(a, flags);
		i++;
	}
	quicksort_a(a, b, len - pushed, flags);
	quicksort_b(a, b, pushed, flags);
}

static void	quicksort_b(t_stack *a, t_stack *b, int len, t_flags *flags)
{
	int	pivot;
	int	pushed;
	int	rotated;
	int	i;

	if (len <= 3)
	{
		sort_small_b(a, b, len, flags);
		return ;
	}
	pivot = get_pivot(b, len);
	pushed = 0;
	rotated = 0;
	i = 0;
	while (i < len)
	{
		if (b->top->index >= pivot)
		{
			pa(a, b, flags);
			pushed++;
		}
		else
		{
			rb(b, flags);
			rotated++;
		}
		i++;
	}
	i = 0;
	while (i < rotated)
	{
		rrb(b, flags);
		i++;
	}
	quicksort_a(a, b, pushed, flags);
	quicksort_b(a, b, len - pushed, flags);
}

void	sort_complex(t_stack *a, t_stack *b, t_flags *flags)
{
	quicksort_a(a, b, a->size, flags);
}
