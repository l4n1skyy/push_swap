/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 22:32:52 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/22 14:07:45 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_sort(t_node **head, int strategy, int benchmark)
{
	float	disorder;
	t_bench	bench;
	t_bench	*bench_ptr;
	int		used_strategy;

	bench = (t_bench){0};
	bench.print = 1;
	bench_ptr = &bench;
	disorder = compute_disorder(*head);
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
