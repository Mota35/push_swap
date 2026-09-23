/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:03:11 by gumota            #+#    #+#             */
/*   Updated: 2026/09/18 13:01:02 by orclaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *a, t_stack *b, t_flags *flags)
{
	t_node	*aux;

	if (!a->top)
		return ;
	aux = a->top;
	a->top = aux->next;
	aux->next = b->top;
	b->top = aux;
	a->size--;
	b->size++;
	write (1, "pb\n", 3);
	if (flags)
		flags->pb++;
}
