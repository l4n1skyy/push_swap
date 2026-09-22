/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:27:25 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/21 22:30:36 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_top(t_node **src, t_node **dst)
{
	t_node	*node;
	t_node	*new_src;
	t_node	*old_dst;

	node = *src;
	new_src = node->next;
	*src = new_src;
	if (new_src != NULL)
		new_src->prev = NULL;
	node->prev = NULL;
	old_dst = *dst;
	node->next = old_dst;
	if (old_dst != NULL)
		old_dst->prev = node;
	*dst = node;
}

void	pa(t_node **b, t_node **a, t_bench *bench)
{
	if (!b || !a || !*b)
		return ;
	push_top(b, a);
	if (bench)
		bench->pa++;
	if (bench && bench->print)
		write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b, t_bench *bench)
{
	if (!a || !b || !*a)
		return ;
	push_top(a, b);
	if (bench)
		bench->pb++;
	if (bench && bench->print)
		write(1, "pb\n", 3);
}
