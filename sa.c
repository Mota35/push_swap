/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 12:59:23 by gumota            #+#    #+#             */
/*   Updated: 2026/09/16 19:33:17 by orclaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, t_flags *flags)
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
	write(1, "sa\n", 3);
	if (flags)
		flags->sa++;
}
