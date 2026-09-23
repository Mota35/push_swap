/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 15:11:02 by gumota            #+#    #+#             */
/*   Updated: 2026/09/15 10:55:33 by gumota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**dup_argv(char **argv, int n)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (n + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < n)
	{
		copy[i] = ft_strdup(argv[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static int	veri_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_quant_nums(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**normalise_args(int argc, char **argv, int *nbr_args)
{
	char	**nums;

	if (argc <= 0 || !argv || !argv[0])
	{
		*nbr_args = 0;
		return (NULL);
	}
	if (argc > 1)
	{
		*nbr_args = argc;
		return (dup_argv(argv, argc));
	}
	if (!veri_space(*argv))
	{
		*nbr_args = 1;
		return (dup_argv(argv, 1));
	}
	nums = ft_split(argv[0], ' ');
	*nbr_args = ft_quant_nums(nums);
	return (nums);
}
