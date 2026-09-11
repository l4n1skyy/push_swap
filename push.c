/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:27:25 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/11 14:59:03 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top(t_node **src, t_node **dst)
{
	t_node	*node;
	t_node	*new_src;
	t_node	*old_dst;

	if (!src || !dst || !*src)
		return ;

	//save current top of src
	node = *src;

	//remove node from src
	new_src = node->next;
	*src = new_src;
	if (new_src != NULL)
		new_src->prev = NULL;

	//save current top of dst
	old_dst = *dst;

	//connect node to dst
	node->next = old_dst;
	if (old_dst != NULL)
		old_dst->prev = node;

	//make node new top of dst
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