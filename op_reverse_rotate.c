/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 15:00:32 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/21 22:31:06 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;
	t_node	*new_end;

	first = *head;
	last = first;
	while (last->next)
		last = last->next;
	new_end = last->prev;
	new_end->next = NULL;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	*head = last;
}

void	rra(t_node **a, t_bench *bench)
{
	if (!a || !*a || !(*a)->next)
		return ;
	reverse_rotate(a);
	if (bench)
		bench->rra++;
	if (bench && bench->print)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, t_bench *bench)
{
	if (!b || !*b || !(*b)->next)
		return ;
	reverse_rotate(b);
	if (bench)
		bench->rrb++;
	if (bench && bench->print)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b, t_bench *bench)
{
	int	executed;

	executed = 0;
	if (a && *a && (*a)->next)
	{
		reverse_rotate(a);
		executed = 1;
	}
	if (b && *b && (*b)->next)
	{
		reverse_rotate(b);
		executed = 1;
	}
	if (!executed)
		return ;
	if (bench)
		bench->rrr++;
	if (bench && bench->print)
		write(1, "rrr\n", 4);
}
