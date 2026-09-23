/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 16:40:52 by gumota            #+#    #+#             */
/*   Updated: 2026/09/15 16:48:15 by gumota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, t_flags *flags)
{
	t_node	*last;
	t_node	*antes_last;

	if (!a->top || !a->top->next)
		return ;
	antes_last = a->top;
	while (antes_last->next->next)
		antes_last = antes_last->next;
	last = antes_last->next;
	antes_last->next = NULL;
	last->next = a->top;
	a->top = last;
	write(1, "rra\n", 4);
	if (flags)
		flags->rra++;
}
