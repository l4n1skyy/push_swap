/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 22:57:37 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/21 23:22:55 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_node **a, t_bench *bench);
static void	sort_five(t_node **a, t_bench *bench);

int	sort_small(t_node **a, int limit, t_bench *bench)
{
	if (limit == 2)
	{
		if ((*a)->rank > (*a)->next->rank)
			sa(a, bench);
		return (1);
	}
	if (limit == 3)
	{
		sort_three(a, bench);
		return (1);
	}
	if (limit == 5)
	{
		sort_five(a, bench);
		return (1);
	}
	return (0);
}

static void	sort_five(t_node **a, t_bench *bench)
{
	t_node	*b;

	b = NULL;
	push_rank_to_b(a, &b, 0, bench);
	push_rank_to_b(a, &b, 1, bench);
	sort_three(a, bench);
	pa(&b, a, bench);
	pa(&b, a, bench);
}

static void	sort_three(t_node **a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->rank;
	second = (*a)->next->rank;
	third = (*a)->next->next->rank;
	if (first > second && second < third && first < third)
		sa(a, bench);
	else if (first > second && second > third)
	{
		sa(a, bench);
		rra(a, bench);
	}
	else if (first > second && second < third && first > third)
		ra(a, bench);
	else if (first < second && second > third && first < third)
	{
		sa(a, bench);
		ra(a, bench);
	}
	else if (first < second && second > third && first > third)
		rra(a, bench);
}
