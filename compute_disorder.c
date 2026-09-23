/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 12:05:24 by gumota            #+#    #+#             */
/*   Updated: 2026/09/16 12:16:44 by gumota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	t_node	*node;
	t_node	*outher;
	int		mistakes;
	int		total_pairs;

	node = a->top;
	mistakes = 0;
	total_pairs = 0;
	while (node)
	{
		outher = node->next;
		while (outher)
		{
			total_pairs++;
			if (node->value > outher->value)
				mistakes++;
			outher = outher->next;
		}
		node = node->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((double)mistakes / (double)total_pairs);
}
