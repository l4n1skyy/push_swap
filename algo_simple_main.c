/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 15:50:42 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/17 18:01:15 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MIN 0
#define MAX 1

static void	push_to_b(t_node **a, t_node **b, int size, t_bench *bench)
{
	int	i;
	int	current_type;
	int	previous_type;

	i = 0;
	previous_type = -1;
	while (i < size)
	{
		current_type = find_cheapest_extreme(*a);
		reposition_extreme(a, current_type, bench);
		if (previous_type == MAX)
			rb(b, bench);
		pb(a, b, bench);
		previous_type = current_type;
		i++;
	}
}

static void	push_to_a(t_node **a, t_node **b, int size, t_bench *bench)
{
	int	i;

	rotate_b_for_max(b, bench);
	i = 0;
	while (i < size)
	{
		pa(b, a, bench);
		i++;
	}
}

void	minmax_sort(t_node **head, t_bench *bench)
{
	t_node	*a;
	t_node	*b;
	int		size;

	a = *head;
	b = NULL;
	size = ft_llstsize(a);
	push_to_b(&a, &b, size, bench);
	push_to_a(&a, &b, size, bench);
	*head = a;
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	// t_node	*tmp;

	if (argc <= 1)
		return (0);

	a = create_struct(argv);
	if (!a)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}

	b = NULL;

	minmax_sort(&a);

	// printf("A: ");
	// tmp = a;
	// while (tmp)
	// {
	// 	printf("%d ", tmp->number);
	// 	tmp = tmp->next;
	// }
	// printf("\n");

	// printf("B: ");
	// tmp = b;
	// while (tmp)
	// {
	// 	printf("%d ", tmp->number);
	// 	tmp = tmp->next;
	// }
	// printf("\n");

	ft_llstclear(&a);
	ft_llstclear(&b);
	return (0);
}
*/
