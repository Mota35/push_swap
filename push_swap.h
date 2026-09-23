/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumota <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 11:43:55 by gumota            #+#    #+#             */
/*   Updated: 2026/09/22 13:43:26 by gumota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_flags
{
	t_strategy	flags;
	int			erro;
	int			bench;
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
	int			total_ops;
	double		disorder;
}	t_flags;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}			t_stack;

int		ft_strlen(const char *str);
t_flags	parse_flags(int *argc, char ***argv);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);

char	**normalise_args(int argc, char **argv, int *nbr_args);
int		parse_and_fill(char **nums, int n, t_stack *a);
long	ft_atoi(const char *nptr, int *temp);
void	stack_init(t_stack *t, int *valores, int n);

void	run_strategy(t_stack *a, t_stack *b, t_flags *flags);
void	sa(t_stack *a, t_flags *flags);
void	sb(t_stack *b, t_flags *flags);
void	ss(t_stack *a, t_stack *b, t_flags *flags);
void	pa(t_stack *a, t_stack *b, t_flags *flags);
void	pb(t_stack *a, t_stack *b, t_flags *flags);
void	ra(t_stack *a, t_flags *flags);
void	rb(t_stack *b, t_flags *flags);
void	rr(t_stack *a, t_stack *b, t_flags *flags);
void	rra(t_stack *a, t_flags *flags);
void	rrb(t_stack *b, t_flags *flags);
void	rrr(t_stack *a, t_stack *b, t_flags *flags);
void	sort_simple(t_stack *a, t_stack *b, t_flags *flags);
void	sort_medium(t_stack *a, t_stack *b, t_flags *flags);
void	sort_complex(t_stack *a, t_stack *b, t_flags *flags);
void	sort_adaptive(t_stack *a, t_stack *b, t_flags *flags);

int		is_sorted(t_stack *st);
double	compute_disorder(t_stack *a);

int		get_pivot(t_stack *a, int len);
void	sort_small_b(t_stack *a, t_stack *b, int len, t_flags *flags);
void	sort_small_a(t_stack *a, int len, t_flags *flags);

#endif
