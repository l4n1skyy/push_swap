/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:32:30 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/15 14:56:21 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top(t_node **head)
{
	t_node	*first;
	t_node	*second;
	t_node	*temp;

	if (!head || !*head || !(*head)->next)
		return ;
	//save nodes first
	first = *head;
	second = (*head)->next;
	temp = second->next;

	//change first
	first->prev = second;
	first->next = temp;

	//change second
	second->prev = NULL;
	second->next = first;

	//fix third
	if (temp != NULL)
		temp->prev = first;

	//update head
	*head = second;
}

void	sa(t_node **a)
{
	swap_top(a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	swap_top(b);
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	swap_top(a);
	swap_top(b);
	write(1, "ss\n", 3);
}

