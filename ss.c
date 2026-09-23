/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 13:45:10 by gumota            #+#    #+#             */
/*   Updated: 2026/09/15 13:47:48 by gumota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sa_no_print(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (!a->top || !a->top->next)
		return ;
	first = a->top;
	second = a->top->next;
	a->top = second;
	first->next = second->next;
	second->next = first;
}

static void	sb_no_print(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!b->top || !b->top->next)
		return ;
	first = b->top;
	second = b->top->next;
	b->top = second;
	first->next = second->next;
	second->next = first;
}

void	ss(t_stack *a, t_stack *b, t_flags *flags)
{
	sa_no_print(a);
	sb_no_print(b);
	write(1, "ss\n", 3);
	if (flags)
		flags->ss++;
}
