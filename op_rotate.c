/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 22:49:11 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/21 22:31:32 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;
	t_node	*new_head;

	first = *head;
	last = first;
	while (last->next)
		last = last->next;
	new_head = first->next;
	new_head->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	*head = new_head;
}

void	ra(t_node **a, t_bench *bench)
{
	if (!a || !*a || !(*a)->next)
		return ;
	rotate(a);
	if (bench)
		bench->ra++;
	write(1, "ra\n", 3);
}

void	rb(t_node **b, t_bench *bench)
{
	if (!b || !*b || !(*b)->next)
		return ;
	rotate(b);
	if (bench)
		bench->rb++;
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b, t_bench *bench)
{
	int	executed;

	executed = 0;
	if (a && *a && (*a)->next)
	{
		rotate (a);
		executed = 1;
	}
	if (b && *b && (*b)->next)
	{
		rotate (b);
		executed = 1;
	}
	if (!executed)
		return ;
	if (bench)
		bench->rr++;
	write(1, "rr\n", 3);
}
