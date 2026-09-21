/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 15:50:42 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/17 14:30:03 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MIN 0
#define MAX 1

static int	find_min(t_node *head)
{
	int	min;

	min = head->number;
	while (head)
	{
		if (head->number < min)
			min = head->number;
		head = head->next;
	}
	return (min);
}

static int	find_max(t_node *head)
{
	int	max;

	max = head->number;
	while (head)
	{
		if (head->number > max)
			max = head->number;
		head = head->next;
	}
	return (max);
}

static int	find_position(t_node *head, int value)
{
	int	position;

	position = 0;
	while (head)
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

static int	find_cheapest_extreme(t_node *head)
{
	int	min_cost;
	int	max_cost;

	min_cost = extreme_cost(head, MIN);
	max_cost = extreme_cost(head, MAX);
	if (min_cost <= max_cost)
		return (MIN);
	return (MAX);
}
static void	reposition_extreme(t_node **head, int type, t_bench *bench)
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

static void	rotate_b_for_max(t_node **b, t_bench *bench)
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

static void	push_to_b(t_node **a, t_node **b, int size, t_bench *bench)
{
	int	i;
	int	current_type;
	int	previous_type;

	i = 0;
	previous_type = -1;
	while (i < size)
	{
		current_type = find_cheapest_extreme(*a);
		reposition_extreme(a, current_type, bench);
		if (previous_type == MAX)
			rb(b, bench);
		pb(a, b, bench);
		previous_type = current_type;
		i++;
	}
}

static void	push_to_a(t_node **a, t_node **b, int size, t_bench *bench)
{
	int	i;

	rotate_b_for_max(b, bench);
	i = 0;
	while (i < size)
	{
		pa(b, a, bench);
		i++;
	}
}

void	minmax_selection_sort(t_node **head, t_bench *bench)
{
	t_node	*a;
	t_node	*b;
	int		size;

	a = *head;
	b = NULL;
	size = ft_llstsize(a);
	push_to_b(&a, &b, size, bench);
	push_to_a(&a, &b, size, bench);
	*head = a;
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	// t_node	*tmp;

	if (argc <= 1)
		return (0);

	a = create_struct(argv);
	if (!a)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}

	b = NULL;

	selection_sort(&a);

	// printf("A: ");
	// tmp = a;
	// while (tmp)
	// {
	// 	printf("%d ", tmp->number);
	// 	tmp = tmp->next;
	// }
	// printf("\n");

	// printf("B: ");
	// tmp = b;
	// while (tmp)
	// {
	// 	printf("%d ", tmp->number);
	// 	tmp = tmp->next;
	// }
	// printf("\n");

	ft_llstclear(&a);
	ft_llstclear(&b);
	return (0);
}
*/
