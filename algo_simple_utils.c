/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 17:27:27 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/17 17:45:57 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MIN 0
#define MAX 1

static int	rotation_cost(int position, int size)
{
	if (position <= size / 2)
		return (position);
	return (size - position);
}

static int	extreme_cost(t_node *head, int type)
{
	int	value;
	int	position;
	int	size;

	size = ft_llstsize(head);
	if (type == MIN)
		value = find_min(head);
	else
		value = find_max(head);
	position = find_position(head, value);
	return (rotation_cost(position, size));
}
int	find_cheapest_extreme(t_node *head)
{
	int	min_cost;
	int	max_cost;

	min_cost = extreme_cost(head, MIN);
	max_cost = extreme_cost(head, MAX);
	if (min_cost <= max_cost)
		return (MIN);
	return (MAX);
}

void	reposition_extreme(t_node **head, int type, t_bench *bench)
{
	int	size;
	int	value;
	int	position;

	size = ft_llstsize(*head);
	if (type == MIN)
		value = find_min(*head);
	else
		value = find_max(*head);
	position = find_position(*head, value);
	if (position <= size / 2)
	{
		while (position-- > 0)
			ra(head, bench);
	}
	else
	{
		position = size - position;
		while (position-- > 0)
			rra(head, bench);
	}
}

void	rotate_b_for_max(t_node **b, t_bench *bench)
{
	int	max;
	int	position;
	int	size;

	max = find_max(*b);
	size = ft_llstsize(*b);
	position = find_position(*b, max);
	if (position <= size / 2)
	{
		while (position-- > 0)
			rb(b, bench);
	}
	else
	{
		position = size - position;
		while (position-- > 0)
			rrb(b, bench);
	}
}