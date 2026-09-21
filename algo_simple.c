/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 15:50:42 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/17 16:48:25 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_node **a, t_bench *bench);
static void	push_rank_to_b(t_node **a, t_node **b, int rank,
		int size, t_bench *bench);

static int	find_rank_position(t_node *head, int rank)
{
	int	position;

	position = 0;
	while (head)
	{
		if (head->rank == rank)
			return (position);
		head = head->next;
		position++;
	}
	return (-1);
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

static void	push_rank_to_b(t_node **a, t_node **b, int rank, int size,
	 t_bench *bench)
{
	int	position;

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

static void	sort_five(t_node **a, t_bench *bench)
{
	t_node	*b;

	b = NULL;
	push_rank_to_b(a, &b, 0, 5, bench);
	push_rank_to_b(a, &b, 1, 4, bench);
	sort_three(a, bench);
	pa(&b, a, bench);
	pa(&b, a, bench);
}

static void	push_chunks(t_node **a, t_node **b, int size, t_bench *bench)
{
	int	chunk_count;
	int	chunk_size;
	int	lower;
	int	upper;
	int	count;

	chunk_count = 5;
	if (size > 100)
		chunk_count = 10;
	chunk_size = (size + chunk_count - 1) / chunk_count;
	lower = 0;
	while (lower < size)
	{
		upper = lower + chunk_size;
		count = ft_llstsize(*a);
		while (count-- > 0)
		{
			if ((*a)->rank < upper)
			{
				pb(a, b, bench);
				if ((*b)->rank < lower + chunk_size / 2)
					rb(b, bench);
			}
			else
				ra(a, bench);
		}
		lower = upper;
	}
}

static void	push_max_to_a(t_node **a, t_node **b, int size, t_bench *bench)
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

void	simple_sortv2(t_node **head, int limit, t_bench *bench)
{
	t_node	*a;
	t_node	*b;

	a = *head;
	if (limit == 2)
	{
		if (a->rank > a->next->rank)
			sa(&a, bench);
		*head = a;
		return ;
	}
	if (limit == 3)
	{
		sort_three(&a, bench);
		*head = a;
		return ;
	}
	if (limit == 5)
	{
		sort_five(&a, bench);
		*head = a;
		return ;
	}
	b = NULL;
	push_chunks(&a, &b, limit, bench);
	push_max_to_a(&a, &b, limit, bench);
	*head = a;
}

