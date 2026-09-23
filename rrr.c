/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 16:51:03 by gumota            #+#    #+#             */
/*   Updated: 2026/09/15 16:53:33 by gumota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_no_print(t_stack *a)
{
	t_node	*last;
	t_node	*before_last;

	if (!a->top || !a->top->next)
		return ;
	before_last = a->top;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = a->top;
	a->top = last;
}

void	rrb_no_print(t_stack *b)
{
	t_node	*last;
	t_node	*before_last;

	if (!b->top || !b->top->next)
		return ;
	before_last = b->top;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = b->top;
	b->top = last;
}

void	rrr(t_stack *a, t_stack *b, t_flags *flags)
{
	rra_no_print(a);
	rrb_no_print(b);
	write (1, "rrr\n", 4);
	if (flags)
		flags->rrr++;
}
