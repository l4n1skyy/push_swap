/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 15:50:42 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/15 15:00:22 by jia-xcho         ###   ########.fr       */
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

static int	find_cheapest_extreme(t_node *head)
{
	int	size;
	int	min;
	int	max;
	int	min_position;
	int	max_position;
	int	min_cost;
	int	max_cost;

	size = ft_llstsize(head);
	min = find_min(head);
	max = find_max(head);
	min_position = find_position(head, min);
	max_position = find_position(head, max);
	min_cost = rotation_cost(min_position, size);
	max_cost = rotation_cost(max_position, size);
	if (min_cost <= max_cost)
		return (MIN);
	return (MAX);
}

static void	reposition_extreme(t_node **head, int type)
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
			ra(head);
	}
	else
	{
		position = size - position;
		while (position-- > 0)
			rra(head);
	}
}

static void	rotate_b_for_max(t_node **b)
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
			rb(b);
	}
	else
	{
		position = size - position;
		while (position-- > 0)
			rrb(b);
	}
}

t_node	*selection_sort(t_node *a, t_node *b)
{
	int	size;
	int	i;
	int	current_type;
	int	previous_type;

	size = ft_llstsize(a);
	i = 0;
	previous_type = -1;

	while (i < size)
	{
		current_type = find_cheapest_extreme(a);
		reposition_extreme(&a, current_type);
		if (previous_type == MAX)
			rb(&b);
		pb(&a, &b);
		previous_type = current_type;
		i++;
	}

	rotate_b_for_max(&b);

	i = 0;
	while (i < size)
	{
		pa(&b, &a);
		i++;
	}
	return (a);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_node	*tmp;

	if (argc <= 1)
		return (0);

	a = create_struct(argv);
	if (!a)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}

	b = NULL;

	a = selection_sort(a, b);

	printf("A: ");
	tmp = a;
	while (tmp)
	{
		printf("%d ", tmp->number);
		tmp = tmp->next;
	}
	printf("\n");

	printf("B: ");
	tmp = b;
	while (tmp)
	{
		printf("%d ", tmp->number);
		tmp = tmp->next;
	}
	printf("\n");

	ft_llstclear(&a);
	ft_llstclear(&b);
	return (0);
}
*/