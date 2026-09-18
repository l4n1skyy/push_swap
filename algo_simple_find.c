/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple_find.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 17:33:36 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/17 17:42:18 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_node *head)
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

int	find_max(t_node *head)
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

int	find_position(t_node *head, int value)
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
