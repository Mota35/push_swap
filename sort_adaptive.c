/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 10:22:21 by gumota            #+#    #+#             */
/*   Updated: 2026/09/21 10:22:51 by gumota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_stack *a, t_stack *b, t_flags *flags)
{
	if (flags->disorder < 0.2)
		sort_simple(a, b, flags);
	else if (flags->disorder < 0.5)
		sort_medium(a, b, flags);
	else
		sort_complex(a, b, flags);
}
