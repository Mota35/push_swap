/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 14:07:43 by gumota            #+#    #+#             */
/*   Updated: 2026/09/12 17:36:15 by gumota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	free_if_erro(int **valor)
{
	free (*valor);
	return (0);
}

static int	is_valid_int(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	valor_duplicado(int *valores, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (valores[i] == valores[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	set_indexes(t_stack *stack)
{
	t_node	*node;
	t_node	*other;
	int		rank;

	node = stack->top;
	while (node)
	{
		rank = 0;
		other = stack->top;
		while (other)
		{
			if (other->value < node->value)
				rank++;
			other = other->next;
		}
		node->index = rank;
		node = node->next;
	}
}

int	parse_and_fill(char **nums, int n, t_stack *a)
{
	int	*valores;
	int	temp;
	int	i;

	valores = malloc (n * sizeof(int));
	if (!valores)
		return (0);
	i = 0;
	while (i < n)
	{
		temp = 0;
		if (!is_valid_int(nums[i]))
			return (free_if_erro(&valores));
		else if (!ft_atoi(nums[i], &temp))
			return (free_if_erro(&valores));
		valores[i] = temp;
		i++;
	}
	if (valor_duplicado(valores, n))
		return (free_if_erro(&valores));
	stack_init (a, valores, n);
	set_indexes (a);
	free (valores);
	return (1);
}
