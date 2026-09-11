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

void	swap_top(t_node **head)
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

	new = ft_llstnew(1);
	ft_llstaddback(&a, new);
	new = ft_llstnew(2);
	ft_llstaddback(&a, new);
	new = ft_llstnew(3);
	ft_llstaddback(&a, new);

	new = ft_llstnew(7);
	ft_llstaddback(&b, new);
	new = ft_llstnew(8);
	ft_llstaddback(&b, new);
	new = ft_llstnew(9);
	ft_llstaddback(&b, new);

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