/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 16:28:26 by gumota            #+#    #+#             */
/*   Updated: 2026/09/17 14:40:41 by orclaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push_new(t_stack *st, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->value = value;
	new->index = 0;
	new->next = st->top;
	st->top = new;
	st->size++;
}

void	stack_init(t_stack *t, int *values, int n)
{
	int	i;

	i = n - 1;
	while (i >= 0)
	{
		stack_push_new(t, values[i]);
		i--;
	}
}
