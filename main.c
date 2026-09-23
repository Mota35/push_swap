/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 12:33:49 by gumota            #+#    #+#             */
/*   Updated: 2026/09/16 12:19:17 by gumota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_split(char **nums)
{
	int	i;

	i = 0;
	while (nums[i] != NULL)
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}

static int	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void	print(t_stack *st)
{
	t_node	*node;

	node = st->top;
	while (node)
	{
		printf("%d, ", node->value);
		node = node->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	**nums;
	int		n;
	t_flags	flags;

	a = (t_stack){0};
	b = (t_stack){0};
	if (argc == 1)
		return (0);
	flags = parse_flags(&argc, &argv);
	if (flags.erro || argc == 0)
		return (print_error());
	nums = normalise_args(argc, argv, &n);
	if (!nums || n == 0)
		return (1);
	if (!parse_and_fill(nums, n, &a))
	{
		free_split(nums);
		return (print_error());
	}
	if (!is_sorted(&a))
	{
		flags.disorder = compute_disorder(&a);
		run_strategy(&a, &b, &flags);
	}
	print(&a);
	//printf("Tamanho final de B: %d\n", b.size);
	/*free_stack(&a);
	free_stack(&b);
	free_split(nums);*/
	return (0);
}
