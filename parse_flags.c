/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 12:30:27 by gumota            #+#    #+#             */
/*   Updated: 2026/09/12 14:41:54 by gumota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0 || !s1 || !s2)
		return (0);
	i = 0;
	while (i < n && s1[i] && s2[i]
		&& ((unsigned char)s1[i] == (unsigned char)s2[i]))
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

t_flags	parse_flags(int *argc, char ***argv)
{
	t_flags	flag;
	int		i;

	flag = (t_flags){0};
	flag.flags = ADAPTIVE;
	i = 1;
	while ((*argv)[i] && i < *argc && (ft_strncmp((*argv)[i], "--", 2) == 0))
	{
		if (ft_strcmp((*argv)[i], "--bench") == 0)
			flag.bench = 1;
		else if (ft_strcmp((*argv)[i], "--simple") == 0)
			flag.flags = SIMPLE;
		else if (ft_strcmp((*argv)[i], "--medium") == 0)
			flag.flags = MEDIUM;
		else if (ft_strcmp((*argv)[i], "--complex") == 0)
			flag.flags = COMPLEX;
		else if (ft_strcmp((*argv)[i], "--adaptive") == 0)
			flag.flags = ADAPTIVE;
		else
			flag.erro = 1;
		i++;
	}
	(*argc) -= i;
	(*argv) += i;
	return (flag);
}
