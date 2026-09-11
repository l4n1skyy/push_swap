/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 15:00:32 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/11 15:15:08 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;
	t_node	*new_end;

	if (!head || !*head || !(*head)->next)
		return ;

	//get first and last nodes
	first = *head;
	last = first;
	while (last->next)
		last = last->next;

	//save and set new end
	new_end = last->prev;
	new_end->next = NULL;

	//move last in front of first
	last->next = first;
	last->prev = NULL;

	//connect first to last
	first->prev = last;

	//set new head
	*head = last;
}

void	rra(t_node **a)
{
	reverse_rotate(a);
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

