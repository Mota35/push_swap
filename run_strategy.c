/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_strategy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 11:38:52 by gumota            #+#    #+#             */
/*   Updated: 2026/09/19 15:54:42 by orclaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_strategy(t_stack *a, t_stack *b, t_flags *flags)
{
	if (flags->flags == SIMPLE)
		sort_simple(a, b, flags);
	else if (flags->flags == MEDIUM)
		sort_medium(a, b, flags);
	else if (flags->flags == COMPLEX)
		sort_complex(a, b, flags);
	else
		sort_adaptive(a, b, flags);
	/*if (flags->bench)
		print_bench(flags);*/
}
