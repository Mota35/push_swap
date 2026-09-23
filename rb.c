/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 16:01:04 by gumota            #+#    #+#             */
/*   Updated: 2026/09/19 14:52:39 by orclaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack *b, t_flags *flags)
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
	write (1, "rb\n", 3);
	if (flags)
		flags->rb++;
}
