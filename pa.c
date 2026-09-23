/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 13:49:33 by gumota            #+#    #+#             */
/*   Updated: 2026/09/18 12:54:12 by orclaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b, t_flags *flags)
{
	t_node	*aux;

	if (!b->top)
		return ;
	aux = b->top;
	b->top = aux->next;
	aux->next = a->top;
	a->top = aux;
	a->size++;
	b->size--;
	write (1, "pa\n", 3);
	if (flags)
		flags->pa++;
}
