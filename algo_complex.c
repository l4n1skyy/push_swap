/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 22:05:52 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/21 22:05:55 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	flush(t_node **stack_a, t_node **stack_b, t_bench *bench);
static int	get_bit_count(int max_rank);

void	complex_sort(t_node **head, t_bench *bench)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		max_bits;
	int		i;
	int		count;

	stack_a = *head;
	stack_b = NULL;
	max_bits = get_bit_count(ft_llstsize(stack_a) - 1);
	i = 0;
	while (i < max_bits)
	{
		count = ft_llstsize(stack_a);
		while (count--)
		{
			if ((stack_a->rank >> i) & 1)
				ra(&stack_a, bench);
			else
				pb(&stack_a, &stack_b, bench);
		}
		flush(&stack_a, &stack_b, bench);
		i++;
	}
	*head = stack_a;
}

static void	flush(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	while (*stack_b)
		pa(stack_b, stack_a, bench);
}

static int	get_bit_count(int max_rank)
{
	int	bits;

	bits = 0;
	while (max_rank)
	{
		bits++;
		max_rank >>= 1;
	}
	return (bits);
}
