/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:32:30 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/21 22:32:01 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top(t_node **head)
{
	t_node	*first;
	t_node	*second;
	t_node	*temp;

	first = *head;
	second = (*head)->next;
	temp = second->next;
	first->prev = second;
	first->next = temp;
	second->prev = NULL;
	second->next = first;
	if (temp != NULL)
		temp->prev = first;
	*head = second;
}

void	sa(t_node **a, t_bench *bench)
{
	if (!a || !*a || !(*a)->next)
		return ;
	swap_top(a);
	if (bench)
		bench->sa++;
	if (bench && bench->print)
		write(1, "sa\n", 3);
}

void	sb(t_node **b, t_bench *bench)
{
	if (!b || !*b || !(*b)->next)
		return ;
	swap_top(b);
	if (bench)
		bench->sb++;
	if (bench && bench->print)
		write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b, t_bench *bench)
{
	int	executed;

	executed = 0;
	if (a && *a && (*a)->next)
	{
		swap_top(a);
		executed = 1;
	}
	if (b && *b && (*b)->next)
	{
		swap_top(b);
		executed = 1;
	}
	if (!executed)
		return ;
	if (bench)
		bench->ss++;
	if (bench && bench->print)
		write(1, "ss\n", 3);
}
