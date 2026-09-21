#include "push_swap.h"

#define MIN 0
#define MAX 1

static int	find_min(t_node *head, int limit)
{
	int	min;

	min = head->number;
	while (head && limit-- > 0)
	{
		if (head->number < min)
			min = head->number;
		head = head->next;
	}
	return (min);
}

static int	find_max(t_node *head, int limit)
{
	int	max;

	max = head->number;
	while (head && limit-- > 0)
	{
		if (head->number > max)
			max = head->number;
		head = head->next;
	}
	return (max);
}

static int	find_position(t_node *head, int value, int limit)
{
	int	position;

	position = 0;
	while (head && limit-- > 0)
	{
		if (head->number == value)
			return (position);
		head = head->next;
		position++;
	}
	return (-1);
}

static int	rotation_cost(int position, int size)
{
	if (position <= size / 2)
		return (position);
	return (size - position);
}

static int	extreme_cost(t_node *head, int type, int limit)
{
	int	value;
	int	position;

	if (type == MIN)
		value = find_min(head, limit);
	else
		value = find_max(head, limit);
	position = find_position(head, value, limit);
	return (rotation_cost(position, limit));
}

static int	find_cheapest_extreme(t_node *head, int limit)
{
	int	min_cost;
	int	max_cost;

	min_cost = extreme_cost(head, MIN, limit);
	max_cost = extreme_cost(head, MAX, limit);
	if (min_cost <= max_cost)
		return (MIN);
	return (MAX);
}

static void	reposition_extreme(t_node **head, int type, int limit,
	 t_bench *bench)
{
	int	value;
	int	position;

	if (type == MIN)
		value = find_min(*head, limit);
	else
		value = find_max(*head, limit);
	position = find_position(*head, value, limit);
	if (position <= limit / 2)
	{
		while (position-- > 0)
			ra(head, bench);
	}
	else
	{
		position = limit - position;
		while (position-- > 0)
			rra(head, bench);
	}
}

static void	rotate_b_for_max(t_node **b, int limit, t_bench *bench)
{
	int	max;
	int	position;

	max = find_max(*b, limit);
	position = find_position(*b, max, limit);
	if (position <= limit / 2)
	{
		while (position-- > 0)
			rb(b, bench);
	}
	else
	{
		position = limit - position;
		while (position-- > 0)
			rrb(b, bench);
	}
}

void	simple_sort(t_node **head, int limit, t_bench *bench)
{
	t_node	*a;
	t_node	*b;
	int		i;
	int		previous_type;
	int		current_type;

	a = *head;
	b = NULL;
	if (limit <= 1)
		return ;
	i = 0;
	previous_type = -1;
	while (i++ < limit)
	{
		current_type = find_cheapest_extreme(a, limit - i + 1);
		reposition_extreme(&a, current_type, limit - i + 1, bench);
		if (previous_type == MAX)
			rb(&b, bench);
		pb(&a, &b, bench);
		previous_type = current_type;
	}
	rotate_b_for_max(&b, limit, bench);
	i = 0;
	while (i++ < limit)
		pa(&b, &a, bench);
	*head = a;
}
