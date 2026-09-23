/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:35:40 by gumota            #+#    #+#             */
/*   Updated: 2026/09/12 14:09:29 by gumota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cont_words(char const *s, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			cont++;
		i++;
	}
	return (cont);
}

static char	*get_words(char const *s, char c)
{
	int		i;
	int		len;
	char	*ptr;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	**free_grid(char **grid, int i)
{
	while (i > 0)
	{
		i--;
		free(grid[i]);
	}
	free(grid);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**grid;
	int		i;
	int		cont;

	if (!s)
		return (NULL);
	cont = cont_words(s, c);
	grid = (char **)malloc(sizeof(char *) * (cont + 1));
	if (!grid)
		return (NULL);
	i = 0;
	while (i < cont)
	{
		while (*s == c)
			s++;
		grid[i] = get_words(s, c);
		if (!grid[i])
			return (free_grid(grid, i));
		s += ft_strlen(grid[i]);
		i++;
	}
	grid[i] = NULL;
	return (grid);
}
