/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:32:30 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/11 14:59:01 by jia-xcho         ###   ########.fr       */
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
}

void	sb(t_node **b)
{
	swap_top(b);
}

void	ss(t_node **a, t_node **b)
{
	swap_top(a);
	swap_top(b);
}

