/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:27:25 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/10 18:53:08 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top(t_node **src, t_node **dst)
{
	t_node	*node;
	t_node	*new_src;
	t_node	*old_dst;

	if (!src || !*src || !dst)
		return ;
	node = *src;
	new_src = node->next;
	*src = new_src;
	if (new_src != NULL)
		new_src->prev = NULL;
	old_dst = *dst;
	node->next = old_dst;
	if (old_dst != NULL)
		old_dst->prev = node;
	*dst = node;
}

void	pa(t_node **b, t_node **a)
{
	push_top(b, a);
}

void	pb(t_node **a, t_node **b)
{
	push_top(a, b);
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
		printf("A: %d\n", temp->number);
		temp = temp->next;
	}
	temp = b;
	while (temp)
	{
		printf("B: %d\n", temp->number);
		temp = temp->next;
	}
	printf("\npa\n");
	pa(&b, &a);
	temp = a;
	while (temp)
	{
		printf("A: %d\n", temp->number);
		temp = temp->next;
	}
	printf("\n");
	temp = b;
	while (temp)
	{
		printf("B: %d\n", temp->number);
		temp = temp->next;
	}
	printf("\npb\n");
	pb(&a, &b);
	temp = a;
	while (temp)
	{
		printf("A: %d\n", temp->number);
		temp = temp->next;
	}
	printf("\n");
	temp = b;
	while (temp)
	{
		printf("B: %d\n", temp->number);
		temp = temp->next;
	}
}
*/