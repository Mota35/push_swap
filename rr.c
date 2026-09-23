/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 16:07:30 by gumota            #+#    #+#             */
/*   Updated: 2026/09/15 16:13:31 by gumota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ra_no_print(t_stack *a)
{
	t_node	*first;
	t_node	*last;

	if (!a->top || a->size < 2)
		return ;
	first = a->top;
	a->top = first->next;
	last = a->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rb_no_print(t_stack *b)
{
	t_node	*first;
	t_node	*last;

	if (!b->top || b->size < 2)
		return ;
	first = b->top;
	b->top = first->next;
	last = b->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rr(t_stack *a, t_stack *b, t_flags *flags)
{
	ra_no_print(a);
	rb_no_print(b);
	write(1, "rr\n", 3);
	if (flags)
		flags->rr++;
}
