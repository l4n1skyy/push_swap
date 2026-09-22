/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 22:05:52 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/21 22:05:55 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	distribute_bucket(t_chunk_info *info, int lower, int upper);
static void	sort_bucket(t_chunk_info *info, int lower, int upper);
static void	move_rank_to_a(t_chunk_info *info, int rank);

void	medium_sort(t_node **head, t_bench *bench)
{
	t_chunk_info	info;
	t_node			*stack_b;
	int				chunk_size;
	int				upper;
	int				lower;

	stack_b = NULL;
	info.stack_a = head;
	info.stack_b = &stack_b;
	info.bench = bench;
	info.n_node = ft_llstsize(*head);
	info.n_bucket = ft_sqrt(info.n_node) / 2;
	if (info.n_bucket < 1)
		info.n_bucket = 1;
	chunk_size = (info.n_node + info.n_bucket - 1) / info.n_bucket;
	upper = info.n_node;
	while (upper > 0)
	{
		lower = upper - chunk_size;
		if (lower < 0)
			lower = 0;
		distribute_bucket(&info, lower, upper);
		sort_bucket(&info, lower, upper);
		upper = lower;
	}
}

static void	distribute_bucket(t_chunk_info *info, int lower, int upper)
{
	int	size;

	size = ft_llstsize(*info->stack_a);
	while (size-- > 0)
	{
		if ((*info->stack_a)->rank >= lower
			&& (*info->stack_a)->rank < upper)
			pb(info->stack_a, info->stack_b, info->bench);
		else
			ra(info->stack_a, info->bench);
	}
}

static void	sort_bucket(t_chunk_info *info, int lower, int upper)
{
	int	rank;

	rank = upper - 1;
	while (rank >= lower)
	{
		move_rank_to_a(info, rank);
		rank--;
	}
}

static void	move_rank_to_a(t_chunk_info *info, int rank)
{
	int	position;
	int	size;

	size = ft_llstsize(*info->stack_b);
	position = find_rank_position(*info->stack_b, rank);
	if (position < 0)
		return ;
	if (position <= size / 2)
	{
		while (position-- > 0)
			rb(info->stack_b, info->bench);
	}
	else
	{
		position = size - position;
		while (position-- > 0)
			rrb(info->stack_b, info->bench);
	}
	pa(info->stack_b, info->stack_a, info->bench);
}
