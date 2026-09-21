/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 22:32:52 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/21 22:33:23 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *head)
{
	while (head)
	{
		printf("%d ", head->number);
		head = head->next;
	}
	printf("\n");
}

void	run_sort(t_node **head, int strategy, int benchmark)
{
	float	disorder;
	t_bench	bench;
	t_bench	*bench_ptr;
	int		used_strategy;

	bench = (t_bench){0};
	bench_ptr = NULL;
	disorder = compute_disorder(*head);
	if (benchmark)
		bench_ptr = &bench;
	if (disorder != 0.0)
		used_strategy = select_strategy(head, strategy, disorder, bench_ptr);
	else
		used_strategy = strategy;
	if (benchmark)
	{
		print_disorder(disorder);
		print_strategy(strategy, used_strategy);
		print_total_operations(&bench);
		print_swap_push(&bench);
		print_rotate_rrotate(&bench);
	}
}

int	handle_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

t_node	*handle_fail(t_node **head)
{
	ft_llstclear(head);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_node	*head;
	int		strategy;
	int		benchmark;

	if (argc <= 1)
		return (0);
	argv = parse_options(argv, &strategy, &benchmark);
	if (!argv)
		return (handle_error());
	head = create_struct(argv);
	if (!head)
		return (handle_error());
	run_sort(&head, strategy, benchmark);
	ft_llstclear(&head);
	return (0);
}
