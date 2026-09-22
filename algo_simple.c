/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 22:57:37 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/21 23:22:55 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunks(t_node **a, t_node **b, int size, t_bench *bench);
static void	distribute_chunk(t_range *r);

void	simple_sort(t_node **head, int limit, t_bench *bench)
{
	t_node	*a;
	t_node	*b;

	a = *head;
	if (sort_small(&a, limit, bench))
	{
		*head = a;
		return ;
	}
	b = NULL;
	push_chunks(&a, &b, limit, bench);
	push_max_to_a(&a, &b, limit, bench);
	*head = a;
}

static void	push_chunks(t_node **a, t_node **b, int size, t_bench *bench)
{
	t_range	r;
	int		chunk_count;
	int		chunk_size;

	chunk_count = 5;
	if (size > 100)
		chunk_count = 10;
	chunk_size = (size + chunk_count - 1) / chunk_count;
	r.a = a;
	r.b = b;
	r.bench = bench;
	r.lower = 0;
	while (r.lower < size)
	{
		r.upper = r.lower + chunk_size;
		distribute_chunk(&r);
		r.lower = r.upper;
	}
}

static void	distribute_chunk(t_range *r)
{
	int	count;

	count = ft_llstsize(*r->a);
	while (count-- > 0)
	{
		if ((*r->a)->rank < r->upper)
		{
			pb(r->a, r->b, r->bench);
			if ((*r->b)->rank < r->lower + (r->upper - r->lower) / 2)
				rb(r->b, r->bench);
		}
		else
			ra(r->a, r->bench);
	}
}

void	push_rank_to_b(t_node **a, t_node **b, int rank, t_bench *bench)
{
	int	position;
	int	size;

	size = ft_llstsize(*a);
	position = find_rank_position(*a, rank);
	if (position <= size / 2)
	{
		while (position-- > 0)
			ra(a, bench);
	}
	else
	{
		position = size - position;
		while (position-- > 0)
			rra(a, bench);
	}
	pb(a, b, bench);
}

void	push_max_to_a(t_node **a, t_node **b, int size, t_bench *bench)
{
	int	rank;
	int	position;

	rank = size - 1;
	while (rank >= 0)
	{
		position = find_rank_position(*b, rank);
		if (position <= ft_llstsize(*b) / 2)
		{
			while (position-- > 0)
				rb(b, bench);
		}
		else
		{
			position = ft_llstsize(*b) - position;
			while (position-- > 0)
				rrb(b, bench);
		}
		pa(b, a, bench);
		rank--;
	}
}
