/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 22:49:11 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/11 15:03:51 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;
	t_node	*new_head;

	if (!head || !*head || !(*head)->next)
		return ;

	//get first and last nodes
	first = *head;
	last = first;
	while (last->next)
		last = last->next;

	//set new head
	new_head = first->next;
	new_head->prev = NULL;

	//move first behind last
	first->next = NULL;
	first->prev = last;

	//connect last to first
	last->next = first;

	*head = new_head;
}

void	ra(t_node **a)
{
	rotate(a);
}

void	rb(t_node **b)
{
	rotate(b);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
}

#include <stdio.h>
int main(void)
{
	t_node	*a;
	t_node	*new;
	t_node	*temp;

	a = NULL;

	new = ft_llstnew(1);
	ft_llstaddback(&a, new);
	new = ft_llstnew(2);
	ft_llstaddback(&a, new);
	// new = ft_llstnew(3);
	// ft_llstaddback(&a, new);

	temp = a;
	printf("Before:\n");
	while (temp)
	{
		printf("A: %d\n", temp->number);
		temp = temp->next;
	}
	printf("ra\n");
	ra(&a);
	temp = a;
	while (temp)
	{
		printf("A:: %d\n", temp->number);
		temp = temp->next;
	}
}
