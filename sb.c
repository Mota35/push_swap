/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 13:22:36 by gumota            #+#    #+#             */
/*   Updated: 2026/09/15 13:34:03 by gumota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *b, t_flags *flags)
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
	write(1, "sb\n", 3);
	if (flags)
		flags->sb++;
}
