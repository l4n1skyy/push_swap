/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 14:32:30 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/10 15:13:02 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_node **head)
{
	t_node	*first;
	t_node	*second;
	t_node	*temp;

	if (!head || !*head || !(*head)->next)
		return ;
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
/*
#include <stdio.h>
int main(void)
{
	t_node	*a;
	t_node  *b;
	t_node	*new;
	t_node	*temp;

	a = NULL;
	b = NULL;

	new = create_node(1);
	node_add_back(&a, new);
	new = create_node(2);
	node_add_back(&a, new);
	new = create_node(3);
	node_add_back(&a, new);

	new = create_node(7);
	node_add_back(&b, new);
	new = create_node(8);
	node_add_back(&b, new);
	new = create_node(9);
	node_add_back(&b, new);

	temp = a;
	while (temp)
	{
		printf("number A: %d\n", temp->number);
		temp = temp->next;
	}
	temp = b;
	while (temp)
	{
		printf("number B: %d\n", temp->number);
		temp = temp->next;
	}
	printf("sa\n");
	sa(&a);
	temp = a;
	while (temp)
	{
		printf("number: %d\n", temp->number);
		temp = temp->next;
	}
	sb(&b);
	temp = b;
	while (temp)
	{
		printf("number: %d\n", temp->number);
		temp = temp->next;
	}
	printf("ss\n");
	ss(&a, &b);
	temp = a;
	while (temp)
	{
		printf("number: %d\n", temp->number);
		temp = temp->next;
	}
	temp = b;
	while (temp)
	{
		printf("number: %d\n", temp->number);
		temp = temp->next;
	}
}
*/